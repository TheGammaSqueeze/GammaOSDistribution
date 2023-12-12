#!/usr/bin/python
#
# Copyright 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import ctypes
import errno
import os
import socket
import subprocess
import tempfile
import unittest

import bpf
from bpf import BPF_ADD
from bpf import BPF_AND
from bpf import BPF_CGROUP_INET_EGRESS
from bpf import BPF_CGROUP_INET_INGRESS
from bpf import BPF_CGROUP_INET_SOCK_CREATE
from bpf import BPF_DW
from bpf import BPF_F_RDONLY
from bpf import BPF_F_WRONLY
from bpf import BPF_FUNC_get_current_uid_gid
from bpf import BPF_FUNC_get_socket_cookie
from bpf import BPF_FUNC_get_socket_uid
from bpf import BPF_FUNC_ktime_get_boot_ns
from bpf import BPF_FUNC_ktime_get_ns
from bpf import BPF_FUNC_map_lookup_elem
from bpf import BPF_FUNC_map_update_elem
from bpf import BPF_FUNC_skb_change_head
from bpf import BPF_JNE
from bpf import BPF_MAP_TYPE_HASH
from bpf import BPF_PROG_TYPE_CGROUP_SKB
from bpf import BPF_PROG_TYPE_CGROUP_SOCK
from bpf import BPF_PROG_TYPE_SCHED_CLS
from bpf import BPF_PROG_TYPE_SOCKET_FILTER
from bpf import BPF_REG_0
from bpf import BPF_REG_1
from bpf import BPF_REG_10
from bpf import BPF_REG_2
from bpf import BPF_REG_3
from bpf import BPF_REG_4
from bpf import BPF_REG_6
from bpf import BPF_REG_7
from bpf import BPF_STX
from bpf import BPF_W
from bpf import BPF_XADD
from bpf import BpfAlu64Imm
from bpf import BpfExitInsn
from bpf import BpfFuncCall
from bpf import BpfJumpImm
from bpf import BpfLdxMem
from bpf import BpfLoadMapFd
from bpf import BpfMov64Imm
from bpf import BpfMov64Reg
from bpf import BpfProgAttach
from bpf import BpfProgAttachSocket
from bpf import BpfProgDetach
from bpf import BpfProgLoad
from bpf import BpfRawInsn
from bpf import BpfStMem
from bpf import BpfStxMem
from bpf import CreateMap
from bpf import DeleteMap
from bpf import GetFirstKey
from bpf import GetNextKey
from bpf import LookupMap
from bpf import UpdateMap
import csocket
import net_test
from net_test import LINUX_VERSION
import sock_diag

libc = ctypes.CDLL(ctypes.util.find_library("c"), use_errno=True)

HAVE_EBPF_ACCOUNTING = bpf.HAVE_EBPF_4_9
HAVE_EBPF_SOCKET = bpf.HAVE_EBPF_4_14

# bpf_ktime_get_ns() was made non-GPL requiring in 5.8 and at the same time
# bpf_ktime_get_boot_ns() was added, both of these changes were backported to
# Android Common Kernel in 4.14.221, 4.19.175, 5.4.97.
# As such we require 4.14.222+ 4.19.176+ 5.4.98+ 5.8.0+,
# but since we only really care about LTS releases:
HAVE_EBPF_KTIME_GET_NS_APACHE2 = (
    ((LINUX_VERSION > (4, 14, 221)) and (LINUX_VERSION < (4, 19, 0))) or
    ((LINUX_VERSION > (4, 19, 175)) and (LINUX_VERSION < (5, 4, 0))) or
    (LINUX_VERSION > (5, 4, 97))
)
HAVE_EBPF_KTIME_GET_BOOT_NS = HAVE_EBPF_KTIME_GET_NS_APACHE2

KEY_SIZE = 8
VALUE_SIZE = 4
TOTAL_ENTRIES = 20
TEST_UID = 54321
TEST_GID = 12345
# Offset to store the map key in stack register REG10
key_offset = -8
# Offset to store the map value in stack register REG10
value_offset = -16


# Debug usage only.
def PrintMapInfo(map_fd):
  # A random key that the map does not contain.
  key = 10086
  while 1:
    try:
      next_key = GetNextKey(map_fd, key).value
      value = LookupMap(map_fd, next_key)
      print(repr(next_key) + " : " + repr(value.value))  # pylint: disable=superfluous-parens
      key = next_key
    except socket.error:
      print("no value")  # pylint: disable=superfluous-parens
      break


# A dummy loopback function that causes a socket to send traffic to itself.
def SocketUDPLoopBack(packet_count, version, prog_fd):
  family = {4: socket.AF_INET, 6: socket.AF_INET6}[version]
  sock = socket.socket(family, socket.SOCK_DGRAM, 0)
  if prog_fd is not None:
    BpfProgAttachSocket(sock.fileno(), prog_fd)
  net_test.SetNonBlocking(sock)
  addr = {4: "127.0.0.1", 6: "::1"}[version]
  sock.bind((addr, 0))
  addr = sock.getsockname()
  sockaddr = csocket.Sockaddr(addr)
  for _ in range(packet_count):
    sock.sendto("foo", addr)
    data, retaddr = csocket.Recvfrom(sock, 4096, 0)
    assert "foo" == data
    assert sockaddr == retaddr
  return sock


# The main code block for eBPF packet counting program. It takes a preloaded
# key from BPF_REG_0 and use it to look up the bpf map, if the element does not
# exist in the map yet, the program will update the map with a new <key, 1>
# pair. Otherwise it will jump to next code block to handle it.
# REG0: regiter storing return value from helper function and the final return
# value of eBPF program.
# REG1 - REG5: temporary register used for storing values and load parameters
# into eBPF helper function. After calling helper function, the value for these
# registers will be reset.
# REG6 - REG9: registers store values that will not be cleared when calling
# eBPF helper function.
# REG10: A stack stores values need to be accessed by the address. Program can
# retrieve the address of a value by specifying the position of the value in
# the stack.
def BpfFuncCountPacketInit(map_fd):
  key_pos = BPF_REG_7
  return [
      # Get a preloaded key from BPF_REG_0 and store it at BPF_REG_7
      BpfMov64Reg(key_pos, BPF_REG_10),
      BpfAlu64Imm(BPF_ADD, key_pos, key_offset),
      # Load map fd and look up the key in the map
      BpfLoadMapFd(map_fd, BPF_REG_1),
      BpfMov64Reg(BPF_REG_2, key_pos),
      BpfFuncCall(BPF_FUNC_map_lookup_elem),
      # if the map element already exist, jump out of this
      # code block and let next part to handle it
      BpfJumpImm(BPF_AND, BPF_REG_0, 0, 10),
      BpfLoadMapFd(map_fd, BPF_REG_1),
      BpfMov64Reg(BPF_REG_2, key_pos),
      # Initial a new <key, value> pair with value equal to 1 and update to map
      BpfStMem(BPF_W, BPF_REG_10, value_offset, 1),
      BpfMov64Reg(BPF_REG_3, BPF_REG_10),
      BpfAlu64Imm(BPF_ADD, BPF_REG_3, value_offset),
      BpfMov64Imm(BPF_REG_4, 0),
      BpfFuncCall(BPF_FUNC_map_update_elem)
  ]


INS_BPF_EXIT_BLOCK = [
    BpfMov64Imm(BPF_REG_0, 0),
    BpfExitInsn()
]

# Bpf instruction for cgroup bpf filter to accept a packet and exit.
INS_CGROUP_ACCEPT = [
    # Set return value to 1 and exit.
    BpfMov64Imm(BPF_REG_0, 1),
    BpfExitInsn()
]

# Bpf instruction for socket bpf filter to accept a packet and exit.
INS_SK_FILTER_ACCEPT = [
    # Precondition: BPF_REG_6 = sk_buff context
    # Load the packet length from BPF_REG_6 and store it in BPF_REG_0 as the
    # return value.
    BpfLdxMem(BPF_W, BPF_REG_0, BPF_REG_6, 0),
    BpfExitInsn()
]

# Update a existing map element with +1.
INS_PACK_COUNT_UPDATE = [
    # Precondition: BPF_REG_0 = Value retrieved from BPF maps
    # Add one to the corresponding eBPF value field for a specific eBPF key.
    BpfMov64Reg(BPF_REG_2, BPF_REG_0),
    BpfMov64Imm(BPF_REG_1, 1),
    BpfRawInsn(BPF_STX | BPF_XADD | BPF_W, BPF_REG_2, BPF_REG_1, 0, 0),
]

INS_BPF_PARAM_STORE = [
    BpfStxMem(BPF_DW, BPF_REG_10, BPF_REG_0, key_offset),
]


@unittest.skipUnless(HAVE_EBPF_ACCOUNTING,
                     "BPF helper function is not fully supported")
class BpfTest(net_test.NetworkTest):

  def setUp(self):
    super(BpfTest, self).setUp()
    self.map_fd = -1
    self.prog_fd = -1
    self.sock = None

  def tearDown(self):
    if self.prog_fd >= 0:
      os.close(self.prog_fd)
    if self.map_fd >= 0:
      os.close(self.map_fd)
    if self.sock:
      self.sock.close()
    super(BpfTest, self).tearDown()

  def testCreateMap(self):
    key, value = 1, 1
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    UpdateMap(self.map_fd, key, value)
    self.assertEqual(value, LookupMap(self.map_fd, key).value)
    DeleteMap(self.map_fd, key)
    self.assertRaisesErrno(errno.ENOENT, LookupMap, self.map_fd, key)

  def CheckAllMapEntry(self, nonexistent_key, total_entries, value):
    count = 0
    key = nonexistent_key
    while True:
      if count == total_entries:
        self.assertRaisesErrno(errno.ENOENT, GetNextKey, self.map_fd, key)
        break
      else:
        result = GetNextKey(self.map_fd, key)
        key = result.value
        self.assertGreaterEqual(key, 0)
        self.assertEqual(value, LookupMap(self.map_fd, key).value)
        count += 1

  def testIterateMap(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    value = 1024
    for key in range(0, TOTAL_ENTRIES):
      UpdateMap(self.map_fd, key, value)
    for key in range(0, TOTAL_ENTRIES):
      self.assertEqual(value, LookupMap(self.map_fd, key).value)
    self.assertRaisesErrno(errno.ENOENT, LookupMap, self.map_fd, 101)
    nonexistent_key = -1
    self.CheckAllMapEntry(nonexistent_key, TOTAL_ENTRIES, value)

  def testFindFirstMapKey(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    value = 1024
    for key in range(0, TOTAL_ENTRIES):
      UpdateMap(self.map_fd, key, value)
    first_key = GetFirstKey(self.map_fd)
    key = first_key.value
    self.CheckAllMapEntry(key, TOTAL_ENTRIES - 1, value)

  def testRdOnlyMap(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES, map_flags=BPF_F_RDONLY)
    value = 1024
    key = 1
    self.assertRaisesErrno(errno.EPERM, UpdateMap, self.map_fd, key, value)
    self.assertRaisesErrno(errno.ENOENT, LookupMap, self.map_fd, key)

  def testWrOnlyMap(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES, map_flags=BPF_F_WRONLY)
    value = 1024
    key = 1
    UpdateMap(self.map_fd, key, value)
    self.assertRaisesErrno(errno.EPERM, LookupMap, self.map_fd, key)

  def testProgLoad(self):
    # Move skb to BPF_REG_6 for further usage
    instructions = [
        BpfMov64Reg(BPF_REG_6, BPF_REG_1)
    ]
    instructions += INS_SK_FILTER_ACCEPT
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SOCKET_FILTER, instructions)
    SocketUDPLoopBack(1, 4, self.prog_fd)
    SocketUDPLoopBack(1, 6, self.prog_fd)

  def testPacketBlock(self):
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SOCKET_FILTER, INS_BPF_EXIT_BLOCK)
    self.assertRaisesErrno(errno.EAGAIN, SocketUDPLoopBack, 1, 4, self.prog_fd)
    self.assertRaisesErrno(errno.EAGAIN, SocketUDPLoopBack, 1, 6, self.prog_fd)

  def testPacketCount(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    key = 0xf0f0
    # Set up instruction block with key loaded at BPF_REG_0.
    instructions = [
        BpfMov64Reg(BPF_REG_6, BPF_REG_1),
        BpfMov64Imm(BPF_REG_0, key)
    ]
    # Concatenate the generic packet count bpf program to it.
    instructions += (INS_BPF_PARAM_STORE + BpfFuncCountPacketInit(self.map_fd)
                     + INS_SK_FILTER_ACCEPT + INS_PACK_COUNT_UPDATE
                     + INS_SK_FILTER_ACCEPT)
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SOCKET_FILTER, instructions)
    packet_count = 10
    SocketUDPLoopBack(packet_count, 4, self.prog_fd)
    SocketUDPLoopBack(packet_count, 6, self.prog_fd)
    self.assertEqual(packet_count * 2, LookupMap(self.map_fd, key).value)

  ##############################################################################
  #
  # Test for presence of kernel patch:
  #
  #   ANDROID: net: bpf: Allow TC programs to call BPF_FUNC_skb_change_head
  #
  # 4.14: https://android-review.googlesource.com/c/kernel/common/+/1237789
  #       commit fe82848d9c1c887d2a84d3738c13e644d01b6d6f
  #
  # 4.19: https://android-review.googlesource.com/c/kernel/common/+/1237788
  #       commit 6e04d94ab72435b45c413daff63520fd724e260e
  #
  # 5.4:  https://android-review.googlesource.com/c/kernel/common/+/1237787
  #       commit d730995e7bc5b4c10cc176235b704a274e6ec16f
  #
  # Upstream in Linux v5.8:
  #   net: bpf: Allow TC programs to call BPF_FUNC_skb_change_head
  #   commit 6f3f65d80dac8f2bafce2213005821fccdce194c
  #
  @unittest.skipUnless(bpf.HAVE_EBPF_4_14,
                       "no bpf_skb_change_head() support for pre-4.14 kernels")
  def testSkbChangeHead(self):
    # long bpf_skb_change_head(struct sk_buff *skb, u32 len, u64 flags)
    instructions = [
        BpfMov64Imm(BPF_REG_2, 14),  # u32 len
        BpfMov64Imm(BPF_REG_3, 0),   # u64 flags
        BpfFuncCall(BPF_FUNC_skb_change_head),
    ] + INS_BPF_EXIT_BLOCK
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SCHED_CLS, instructions,
                               b"Apache 2.0")
    # No exceptions? Good.

  def testKtimeGetNsGPL(self):
    instructions = [BpfFuncCall(BPF_FUNC_ktime_get_ns)] + INS_BPF_EXIT_BLOCK
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SCHED_CLS, instructions)
    # No exceptions? Good.

  ##############################################################################
  #
  # Test for presence of kernel patch:
  #
  #   UPSTREAM: net: bpf: Make bpf_ktime_get_ns() available to non GPL programs
  #
  # 4.14: https://android-review.googlesource.com/c/kernel/common/+/1585269
  #       commit cbb4c73f9eab8f3c8ac29175d45c99ccba382e15
  #
  # 4.19: https://android-review.googlesource.com/c/kernel/common/+/1355243
  #       commit 272e21ccc9a92feeee80aff0587410a314b73c5b
  #
  # 5.4:  https://android-review.googlesource.com/c/kernel/common/+/1355422
  #       commit 45217b91eaaa3a563247c4f470f4cb785de6b1c6
  #
  @unittest.skipUnless(HAVE_EBPF_KTIME_GET_NS_APACHE2,
                       "no bpf_ktime_get_ns() support for non-GPL programs")
  def testKtimeGetNsApache2(self):
    instructions = [BpfFuncCall(BPF_FUNC_ktime_get_ns)] + INS_BPF_EXIT_BLOCK
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SCHED_CLS, instructions,
                               b"Apache 2.0")
    # No exceptions? Good.

  ##############################################################################
  #
  # Test for presence of kernel patch:
  #
  #   BACKPORT: bpf: add bpf_ktime_get_boot_ns()
  #
  # 4.14: https://android-review.googlesource.com/c/kernel/common/+/1585587
  #       commit 34073d7a8ee47ca908b56e9a1d14ca0615fdfc09
  #
  # 4.19: https://android-review.googlesource.com/c/kernel/common/+/1585606
  #       commit 4812ec50935dfe59ba9f48a572e278dd0b02af68
  #
  # 5.4:  https://android-review.googlesource.com/c/kernel/common/+/1585252
  #       commit 57b3f4830fb66a6038c4c1c66ca2e138fe8be231
  #
  @unittest.skipUnless(HAVE_EBPF_KTIME_GET_BOOT_NS,
                       "no bpf_ktime_get_boot_ns() support")
  def testKtimeGetBootNs(self):
    instructions = [
        BpfFuncCall(BPF_FUNC_ktime_get_boot_ns),
    ] + INS_BPF_EXIT_BLOCK
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SCHED_CLS, instructions,
                               b"Apache 2.0")
    # No exceptions? Good.

  def testGetSocketCookie(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    # Move skb to REG6 for further usage, call helper function to get socket
    # cookie of current skb and return the cookie at REG0 for next code block
    instructions = [
        BpfMov64Reg(BPF_REG_6, BPF_REG_1),
        BpfFuncCall(BPF_FUNC_get_socket_cookie)
    ]
    instructions += (INS_BPF_PARAM_STORE + BpfFuncCountPacketInit(self.map_fd)
                     + INS_SK_FILTER_ACCEPT + INS_PACK_COUNT_UPDATE
                     + INS_SK_FILTER_ACCEPT)
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SOCKET_FILTER, instructions)
    packet_count = 10
    def PacketCountByCookie(version):
      self.sock = SocketUDPLoopBack(packet_count, version, self.prog_fd)
      cookie = sock_diag.SockDiag.GetSocketCookie(self.sock)
      self.assertEqual(packet_count, LookupMap(self.map_fd, cookie).value)
      self.sock.close()
    PacketCountByCookie(4)
    PacketCountByCookie(6)

  def testGetSocketUid(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    # Set up the instruction with uid at BPF_REG_0.
    instructions = [
        BpfMov64Reg(BPF_REG_6, BPF_REG_1),
        BpfFuncCall(BPF_FUNC_get_socket_uid)
    ]
    # Concatenate the generic packet count bpf program to it.
    instructions += (INS_BPF_PARAM_STORE + BpfFuncCountPacketInit(self.map_fd)
                     + INS_SK_FILTER_ACCEPT + INS_PACK_COUNT_UPDATE
                     + INS_SK_FILTER_ACCEPT)
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_SOCKET_FILTER, instructions)
    packet_count = 10
    uid = TEST_UID
    with net_test.RunAsUid(uid):
      self.assertRaisesErrno(errno.ENOENT, LookupMap, self.map_fd, uid)
      SocketUDPLoopBack(packet_count, 4, self.prog_fd)
      self.assertEqual(packet_count, LookupMap(self.map_fd, uid).value)
      DeleteMap(self.map_fd, uid)
      SocketUDPLoopBack(packet_count, 6, self.prog_fd)
      self.assertEqual(packet_count, LookupMap(self.map_fd, uid).value)


@unittest.skipUnless(HAVE_EBPF_ACCOUNTING,
                     "Cgroup BPF is not fully supported")
class BpfCgroupTest(net_test.NetworkTest):

  @classmethod
  def setUpClass(cls):
    super(BpfCgroupTest, cls).setUpClass()
    cls._cg_dir = tempfile.mkdtemp(prefix="cg_bpf-")
    cmd = "mount -t cgroup2 cg_bpf %s" % cls._cg_dir
    try:
      subprocess.check_call(cmd.split())
    except subprocess.CalledProcessError:
      # If an exception is thrown in setUpClass, the test fails and
      # tearDownClass is not called.
      os.rmdir(cls._cg_dir)
      raise
    cls._cg_fd = os.open(cls._cg_dir, os.O_DIRECTORY | os.O_RDONLY)

  @classmethod
  def tearDownClass(cls):
    os.close(cls._cg_fd)
    subprocess.call(("umount %s" % cls._cg_dir).split())
    os.rmdir(cls._cg_dir)
    super(BpfCgroupTest, cls).tearDownClass()

  def setUp(self):
    super(BpfCgroupTest, self).setUp()
    self.prog_fd = -1
    self.map_fd = -1

  def tearDown(self):
    if self.prog_fd >= 0:
      os.close(self.prog_fd)
    if self.map_fd >= 0:
      os.close(self.map_fd)
    try:
      BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_EGRESS)
    except socket.error:
      pass
    try:
      BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_INGRESS)
    except socket.error:
      pass
    try:
      BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_SOCK_CREATE)
    except socket.error:
      pass
    super(BpfCgroupTest, self).tearDown()

  def testCgroupBpfAttach(self):
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_CGROUP_SKB, INS_BPF_EXIT_BLOCK)
    BpfProgAttach(self.prog_fd, self._cg_fd, BPF_CGROUP_INET_INGRESS)
    BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_INGRESS)

  def testCgroupIngress(self):
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_CGROUP_SKB, INS_BPF_EXIT_BLOCK)
    BpfProgAttach(self.prog_fd, self._cg_fd, BPF_CGROUP_INET_INGRESS)
    self.assertRaisesErrno(errno.EAGAIN, SocketUDPLoopBack, 1, 4, None)
    self.assertRaisesErrno(errno.EAGAIN, SocketUDPLoopBack, 1, 6, None)
    BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_INGRESS)
    SocketUDPLoopBack(1, 4, None)
    SocketUDPLoopBack(1, 6, None)

  def testCgroupEgress(self):
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_CGROUP_SKB, INS_BPF_EXIT_BLOCK)
    BpfProgAttach(self.prog_fd, self._cg_fd, BPF_CGROUP_INET_EGRESS)
    self.assertRaisesErrno(errno.EPERM, SocketUDPLoopBack, 1, 4, None)
    self.assertRaisesErrno(errno.EPERM, SocketUDPLoopBack, 1, 6, None)
    BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_EGRESS)
    SocketUDPLoopBack(1, 4, None)
    SocketUDPLoopBack(1, 6, None)

  def testCgroupBpfUid(self):
    self.map_fd = CreateMap(BPF_MAP_TYPE_HASH, KEY_SIZE, VALUE_SIZE,
                            TOTAL_ENTRIES)
    # Similar to the program used in testGetSocketUid.
    instructions = [
        BpfMov64Reg(BPF_REG_6, BPF_REG_1),
        BpfFuncCall(BPF_FUNC_get_socket_uid)
    ]
    instructions += (INS_BPF_PARAM_STORE + BpfFuncCountPacketInit(self.map_fd)
                     + INS_CGROUP_ACCEPT + INS_PACK_COUNT_UPDATE
                     + INS_CGROUP_ACCEPT)
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_CGROUP_SKB, instructions)
    BpfProgAttach(self.prog_fd, self._cg_fd, BPF_CGROUP_INET_INGRESS)
    packet_count = 20
    uid = TEST_UID
    with net_test.RunAsUid(uid):
      self.assertRaisesErrno(errno.ENOENT, LookupMap, self.map_fd, uid)
      SocketUDPLoopBack(packet_count, 4, None)
      self.assertEqual(packet_count, LookupMap(self.map_fd, uid).value)
      DeleteMap(self.map_fd, uid)
      SocketUDPLoopBack(packet_count, 6, None)
      self.assertEqual(packet_count, LookupMap(self.map_fd, uid).value)
    BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_INGRESS)

  def checkSocketCreate(self, family, socktype, success):
    try:
      sock = socket.socket(family, socktype, 0)
      sock.close()
    except socket.error as e:
      if success:
        self.fail("Failed to create socket family=%d type=%d err=%s" %
                  (family, socktype, os.strerror(e.errno)))
      return
    if not success:
      self.fail("unexpected socket family=%d type=%d created, should be blocked"
                % (family, socktype))

  def trySocketCreate(self, success):
    for family in [socket.AF_INET, socket.AF_INET6]:
      for socktype in [socket.SOCK_DGRAM, socket.SOCK_STREAM]:
        self.checkSocketCreate(family, socktype, success)

  @unittest.skipUnless(HAVE_EBPF_SOCKET,
                       "Cgroup BPF socket is not supported")
  def testCgroupSocketCreateBlock(self):
    instructions = [
        BpfFuncCall(BPF_FUNC_get_current_uid_gid),
        BpfAlu64Imm(BPF_AND, BPF_REG_0, 0xfffffff),
        BpfJumpImm(BPF_JNE, BPF_REG_0, TEST_UID, 2),
    ]
    instructions += INS_BPF_EXIT_BLOCK + INS_CGROUP_ACCEPT
    self.prog_fd = BpfProgLoad(BPF_PROG_TYPE_CGROUP_SOCK, instructions)
    BpfProgAttach(self.prog_fd, self._cg_fd, BPF_CGROUP_INET_SOCK_CREATE)
    with net_test.RunAsUid(TEST_UID):
      # Socket creation with target uid should fail
      self.trySocketCreate(False)
    # Socket create with different uid should success
    self.trySocketCreate(True)
    BpfProgDetach(self._cg_fd, BPF_CGROUP_INET_SOCK_CREATE)
    with net_test.RunAsUid(TEST_UID):
      self.trySocketCreate(True)

if __name__ == "__main__":
  unittest.main()
