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
#ifndef _UAPI_ASM_X86_SGX_H
#define _UAPI_ASM_X86_SGX_H
#include <linux/types.h>
#include <linux/ioctl.h>
enum sgx_page_flags {
  SGX_PAGE_MEASURE = 0x01,
};
#define SGX_MAGIC 0xA4
#define SGX_IOC_ENCLAVE_CREATE _IOW(SGX_MAGIC, 0x00, struct sgx_enclave_create)
#define SGX_IOC_ENCLAVE_ADD_PAGES _IOWR(SGX_MAGIC, 0x01, struct sgx_enclave_add_pages)
#define SGX_IOC_ENCLAVE_INIT _IOW(SGX_MAGIC, 0x02, struct sgx_enclave_init)
#define SGX_IOC_ENCLAVE_PROVISION _IOW(SGX_MAGIC, 0x03, struct sgx_enclave_provision)
struct sgx_enclave_create {
  __u64 src;
};
struct sgx_enclave_add_pages {
  __u64 src;
  __u64 offset;
  __u64 length;
  __u64 secinfo;
  __u64 flags;
  __u64 count;
};
struct sgx_enclave_init {
  __u64 sigstruct;
};
struct sgx_enclave_provision {
  __u64 fd;
};
struct sgx_enclave_run;
typedef int(* sgx_enclave_user_handler_t) (long rdi, long rsi, long rdx, long rsp, long r8, long r9, struct sgx_enclave_run * run);
struct sgx_enclave_run {
  __u64 tcs;
  __u32 function;
  __u16 exception_vector;
  __u16 exception_error_code;
  __u64 exception_addr;
  __u64 user_handler;
  __u64 user_data;
  __u8 reserved[216];
};
typedef int(* vdso_sgx_enter_enclave_t) (unsigned long rdi, unsigned long rsi, unsigned long rdx, unsigned int function, unsigned long r8, unsigned long r9, struct sgx_enclave_run * run);
#endif
