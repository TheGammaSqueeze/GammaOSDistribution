/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_CXL_MEM_H_
#define _UAPI_CXL_MEM_H_
#include <linux/types.h>
#define CXL_MEM_QUERY_COMMANDS _IOR(0xCE, 1, struct cxl_mem_query_commands)
#define CXL_MEM_SEND_COMMAND _IOWR(0xCE, 2, struct cxl_send_command)
#define CXL_CMDS ___C(INVALID, "Invalid Command"), ___C(IDENTIFY, "Identify Command"), ___C(RAW, "Raw device command"), ___C(GET_SUPPORTED_LOGS, "Get Supported Logs"), ___C(GET_FW_INFO, "Get FW Info"), ___C(GET_PARTITION_INFO, "Get Partition Information"), ___C(GET_LSA, "Get Label Storage Area"), ___C(GET_HEALTH_INFO, "Get Health Info"), ___C(GET_LOG, "Get Log"), ___C(MAX, "invalid / last command")
#define ___C(a,b) CXL_MEM_COMMAND_ID_ ##a
enum {
  CXL_CMDS
};
#undef ___C
#define ___C(a,b) { b }
static const struct {
  const char * name;
} cxl_command_names[] = {
  CXL_CMDS
};
#undef ___C
struct cxl_command_info {
  __u32 id;
  __u32 flags;
#define CXL_MEM_COMMAND_FLAG_MASK GENMASK(0, 0)
  __s32 size_in;
  __s32 size_out;
};
struct cxl_mem_query_commands {
  __u32 n_commands;
  __u32 rsvd;
  struct cxl_command_info __user commands[];
};
struct cxl_send_command {
  __u32 id;
  __u32 flags;
  union {
    struct {
      __u16 opcode;
      __u16 rsvd;
    } raw;
    __u32 rsvd;
  };
  __u32 retval;
  struct {
    __s32 size;
    __u32 rsvd;
    __u64 payload;
  } in;
  struct {
    __s32 size;
    __u32 rsvd;
    __u64 payload;
  } out;
};
#endif
