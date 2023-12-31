/* Generated by gensyscalls.py. Do not edit. */

#include <private/bionic_asm.h>


ENTRY(execve)
    mov     x8, __NR_execve
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(execve)


ENTRY(getuid)
    mov     x8, __NR_getuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getuid)


ENTRY(getgid)
    mov     x8, __NR_getgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getgid)


ENTRY(geteuid)
    mov     x8, __NR_geteuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(geteuid)


ENTRY(getegid)
    mov     x8, __NR_getegid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getegid)


ENTRY(getresuid)
    mov     x8, __NR_getresuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getresuid)


ENTRY(getresgid)
    mov     x8, __NR_getresgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getresgid)


ENTRY(readahead)
    mov     x8, __NR_readahead
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(readahead)


ENTRY(getgroups)
    mov     x8, __NR_getgroups
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getgroups)


ENTRY(getpgid)
    mov     x8, __NR_getpgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getpgid)


ENTRY(getppid)
    mov     x8, __NR_getppid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getppid)


ENTRY(getsid)
    mov     x8, __NR_getsid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getsid)


ENTRY(setsid)
    mov     x8, __NR_setsid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setsid)


ENTRY(setgid)
    mov     x8, __NR_setgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setgid)


ENTRY(setuid)
    mov     x8, __NR_setuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setuid)


ENTRY(setreuid)
    mov     x8, __NR_setreuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setreuid)


ENTRY(setresuid)
    mov     x8, __NR_setresuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setresuid)


ENTRY(setresgid)
    mov     x8, __NR_setresgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setresgid)


ENTRY(__brk)
    mov     x8, __NR_brk
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__brk)
.hidden __brk


ENTRY(kill)
    mov     x8, __NR_kill
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(kill)


ENTRY(tgkill)
    mov     x8, __NR_tgkill
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(tgkill)


ENTRY(__ptrace)
    mov     x8, __NR_ptrace
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__ptrace)
.hidden __ptrace


ENTRY(getrusage)
    mov     x8, __NR_getrusage
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getrusage)


ENTRY(__getpriority)
    mov     x8, __NR_getpriority
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__getpriority)
.hidden __getpriority


ENTRY(setpriority)
    mov     x8, __NR_setpriority
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setpriority)


ENTRY(getrlimit)
    mov     x8, __NR_getrlimit
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getrlimit)

ALIAS_SYMBOL(getrlimit64, getrlimit)


ENTRY(setrlimit)
    mov     x8, __NR_setrlimit
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setrlimit)

ALIAS_SYMBOL(setrlimit64, setrlimit)


ENTRY(prlimit64)
    mov     x8, __NR_prlimit64
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(prlimit64)

ALIAS_SYMBOL(prlimit, prlimit64)


ENTRY(setgroups)
    mov     x8, __NR_setgroups
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setgroups)


ENTRY(setpgid)
    mov     x8, __NR_setpgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setpgid)


ENTRY(setregid)
    mov     x8, __NR_setregid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setregid)


ENTRY(chroot)
    mov     x8, __NR_chroot
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(chroot)


ENTRY(prctl)
    mov     x8, __NR_prctl
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(prctl)


ENTRY(capget)
    mov     x8, __NR_capget
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(capget)


ENTRY(capset)
    mov     x8, __NR_capset
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(capset)


ENTRY(sigaltstack)
    mov     x8, __NR_sigaltstack
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sigaltstack)


ENTRY(acct)
    mov     x8, __NR_acct
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(acct)


ENTRY(read)
    mov     x8, __NR_read
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(read)


ENTRY(write)
    mov     x8, __NR_write
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(write)


ENTRY(pread64)
    mov     x8, __NR_pread64
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(pread64)

ALIAS_SYMBOL(pread, pread64)


ENTRY(pwrite64)
    mov     x8, __NR_pwrite64
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(pwrite64)

ALIAS_SYMBOL(pwrite, pwrite64)


ENTRY(preadv)
    mov     x8, __NR_preadv
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(preadv)

ALIAS_SYMBOL(preadv64, preadv)


ENTRY(pwritev)
    mov     x8, __NR_pwritev
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(pwritev)

ALIAS_SYMBOL(pwritev64, pwritev)


ENTRY(__close)
    mov     x8, __NR_close
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__close)
.hidden __close


ENTRY(__getpid)
    mov     x8, __NR_getpid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__getpid)
.hidden __getpid


ENTRY(memfd_create)
    mov     x8, __NR_memfd_create
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(memfd_create)


ENTRY(munmap)
    mov     x8, __NR_munmap
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(munmap)


ENTRY(__mremap)
    mov     x8, __NR_mremap
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__mremap)
.hidden __mremap


ENTRY(msync)
    mov     x8, __NR_msync
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(msync)


ENTRY(mprotect)
    mov     x8, __NR_mprotect
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mprotect)


ENTRY(madvise)
    mov     x8, __NR_madvise
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(madvise)


ENTRY(process_madvise)
    mov     x8, __NR_process_madvise
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(process_madvise)


ENTRY(mlock)
    mov     x8, __NR_mlock
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mlock)


ENTRY(mlock2)
    mov     x8, __NR_mlock2
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mlock2)


ENTRY(munlock)
    mov     x8, __NR_munlock
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(munlock)


ENTRY(mlockall)
    mov     x8, __NR_mlockall
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mlockall)


ENTRY(munlockall)
    mov     x8, __NR_munlockall
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(munlockall)


ENTRY(mincore)
    mov     x8, __NR_mincore
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mincore)


ENTRY(__ioctl)
    mov     x8, __NR_ioctl
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__ioctl)
.hidden __ioctl


ENTRY(readv)
    mov     x8, __NR_readv
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(readv)


ENTRY(writev)
    mov     x8, __NR_writev
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(writev)


ENTRY(__fcntl)
    mov     x8, __NR_fcntl
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fcntl)
.hidden __fcntl


ENTRY(flock)
    mov     x8, __NR_flock
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(flock)


ENTRY(__fchmod)
    mov     x8, __NR_fchmod
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fchmod)
.hidden __fchmod


ENTRY(__pipe2)
    mov     x8, __NR_pipe2
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__pipe2)
.hidden __pipe2


ENTRY(__dup)
    mov     x8, __NR_dup
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__dup)
.hidden __dup


ENTRY(__dup3)
    mov     x8, __NR_dup3
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__dup3)
.hidden __dup3


ENTRY(fsync)
    mov     x8, __NR_fsync
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fsync)


ENTRY(fdatasync)
    mov     x8, __NR_fdatasync
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fdatasync)


ENTRY(fchown)
    mov     x8, __NR_fchown
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fchown)


ENTRY(sync)
    mov     x8, __NR_sync
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sync)


ENTRY(syncfs)
    mov     x8, __NR_syncfs
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(syncfs)


ENTRY(__fsetxattr)
    mov     x8, __NR_fsetxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fsetxattr)
.hidden __fsetxattr


ENTRY(__fgetxattr)
    mov     x8, __NR_fgetxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fgetxattr)
.hidden __fgetxattr


ENTRY(__flistxattr)
    mov     x8, __NR_flistxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__flistxattr)
.hidden __flistxattr


ENTRY(fremovexattr)
    mov     x8, __NR_fremovexattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fremovexattr)


ENTRY(__getdents64)
    mov     x8, __NR_getdents64
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__getdents64)
.hidden __getdents64


ENTRY(__openat)
    mov     x8, __NR_openat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__openat)
.hidden __openat


ENTRY(__faccessat)
    mov     x8, __NR_faccessat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__faccessat)
.hidden __faccessat


ENTRY(__fchmodat)
    mov     x8, __NR_fchmodat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fchmodat)
.hidden __fchmodat


ENTRY(fchownat)
    mov     x8, __NR_fchownat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fchownat)


ENTRY(fstatat64)
    mov     x8, __NR_newfstatat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fstatat64)

ALIAS_SYMBOL(fstatat, fstatat64)


ENTRY(linkat)
    mov     x8, __NR_linkat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(linkat)


ENTRY(mkdirat)
    mov     x8, __NR_mkdirat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mkdirat)


ENTRY(mknodat)
    mov     x8, __NR_mknodat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mknodat)


ENTRY(readlinkat)
    mov     x8, __NR_readlinkat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(readlinkat)


ENTRY(renameat)
    mov     x8, __NR_renameat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(renameat)


ENTRY(renameat2)
    mov     x8, __NR_renameat2
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(renameat2)


ENTRY(symlinkat)
    mov     x8, __NR_symlinkat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(symlinkat)


ENTRY(unlinkat)
    mov     x8, __NR_unlinkat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(unlinkat)


ENTRY(utimensat)
    mov     x8, __NR_utimensat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(utimensat)


ENTRY(lseek)
    mov     x8, __NR_lseek
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(lseek)

ALIAS_SYMBOL(lseek64, lseek)


ENTRY(ftruncate)
    mov     x8, __NR_ftruncate
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(ftruncate)

ALIAS_SYMBOL(ftruncate64, ftruncate)


ENTRY(sendfile)
    mov     x8, __NR_sendfile
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sendfile)

ALIAS_SYMBOL(sendfile64, sendfile)


ENTRY(truncate)
    mov     x8, __NR_truncate
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(truncate)

ALIAS_SYMBOL(truncate64, truncate)


ENTRY(mmap)
    mov     x8, __NR_mmap
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mmap)

ALIAS_SYMBOL(mmap64, mmap)


ENTRY(fallocate)
    mov     x8, __NR_fallocate
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fallocate)

ALIAS_SYMBOL(fallocate64, fallocate)


ENTRY(__fadvise64)
    mov     x8, __NR_fadvise64
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fadvise64)
.hidden __fadvise64


ENTRY(__fstatfs)
    mov     x8, __NR_fstatfs
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__fstatfs)
.hidden __fstatfs


ENTRY(__statfs)
    mov     x8, __NR_statfs
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__statfs)
.hidden __statfs


ENTRY(fstat64)
    mov     x8, __NR_fstat
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fstat64)

ALIAS_SYMBOL(fstat, fstat64)


ENTRY(chdir)
    mov     x8, __NR_chdir
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(chdir)


ENTRY(mount)
    mov     x8, __NR_mount
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(mount)


ENTRY(umount2)
    mov     x8, __NR_umount2
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(umount2)


ENTRY(__getcwd)
    mov     x8, __NR_getcwd
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__getcwd)
.hidden __getcwd


ENTRY(fchdir)
    mov     x8, __NR_fchdir
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(fchdir)


ENTRY(setxattr)
    mov     x8, __NR_setxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setxattr)


ENTRY(lsetxattr)
    mov     x8, __NR_lsetxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(lsetxattr)


ENTRY(getxattr)
    mov     x8, __NR_getxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getxattr)


ENTRY(lgetxattr)
    mov     x8, __NR_lgetxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(lgetxattr)


ENTRY(listxattr)
    mov     x8, __NR_listxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(listxattr)


ENTRY(llistxattr)
    mov     x8, __NR_llistxattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(llistxattr)


ENTRY(removexattr)
    mov     x8, __NR_removexattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(removexattr)


ENTRY(lremovexattr)
    mov     x8, __NR_lremovexattr
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(lremovexattr)


ENTRY(statx)
    mov     x8, __NR_statx
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(statx)


ENTRY(swapon)
    mov     x8, __NR_swapon
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(swapon)


ENTRY(swapoff)
    mov     x8, __NR_swapoff
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(swapoff)


ENTRY(settimeofday)
    mov     x8, __NR_settimeofday
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(settimeofday)


ENTRY(times)
    mov     x8, __NR_times
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(times)


ENTRY(nanosleep)
    mov     x8, __NR_nanosleep
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(nanosleep)


ENTRY(clock_settime)
    mov     x8, __NR_clock_settime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(clock_settime)


ENTRY(__clock_nanosleep)
    mov     x8, __NR_clock_nanosleep
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__clock_nanosleep)
.hidden __clock_nanosleep


ENTRY(getitimer)
    mov     x8, __NR_getitimer
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getitimer)


ENTRY(setitimer)
    mov     x8, __NR_setitimer
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setitimer)


ENTRY(__timer_create)
    mov     x8, __NR_timer_create
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__timer_create)
.hidden __timer_create


ENTRY(__timer_settime)
    mov     x8, __NR_timer_settime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__timer_settime)
.hidden __timer_settime


ENTRY(__timer_gettime)
    mov     x8, __NR_timer_gettime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__timer_gettime)
.hidden __timer_gettime


ENTRY(__timer_getoverrun)
    mov     x8, __NR_timer_getoverrun
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__timer_getoverrun)
.hidden __timer_getoverrun


ENTRY(__timer_delete)
    mov     x8, __NR_timer_delete
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__timer_delete)
.hidden __timer_delete


ENTRY(timerfd_create)
    mov     x8, __NR_timerfd_create
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(timerfd_create)


ENTRY(timerfd_settime)
    mov     x8, __NR_timerfd_settime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(timerfd_settime)


ENTRY(timerfd_gettime)
    mov     x8, __NR_timerfd_gettime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(timerfd_gettime)


ENTRY(adjtimex)
    mov     x8, __NR_adjtimex
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(adjtimex)


ENTRY(clock_adjtime)
    mov     x8, __NR_clock_adjtime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(clock_adjtime)


ENTRY(__rt_sigaction)
    mov     x8, __NR_rt_sigaction
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigaction)
.hidden __rt_sigaction


ENTRY(__rt_sigpending)
    mov     x8, __NR_rt_sigpending
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigpending)
.hidden __rt_sigpending


ENTRY(__rt_sigprocmask)
    mov     x8, __NR_rt_sigprocmask
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigprocmask)
.hidden __rt_sigprocmask


ENTRY(__rt_sigsuspend)
    mov     x8, __NR_rt_sigsuspend
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigsuspend)
.hidden __rt_sigsuspend


ENTRY(__rt_sigtimedwait)
    mov     x8, __NR_rt_sigtimedwait
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigtimedwait)
.hidden __rt_sigtimedwait


ENTRY(__rt_sigqueueinfo)
    mov     x8, __NR_rt_sigqueueinfo
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__rt_sigqueueinfo)
.hidden __rt_sigqueueinfo


ENTRY(__signalfd4)
    mov     x8, __NR_signalfd4
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__signalfd4)
.hidden __signalfd4


ENTRY(__socket)
    mov     x8, __NR_socket
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__socket)
.hidden __socket


ENTRY(__socketpair)
    mov     x8, __NR_socketpair
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__socketpair)
.hidden __socketpair


ENTRY(bind)
    mov     x8, __NR_bind
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(bind)


ENTRY(__connect)
    mov     x8, __NR_connect
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__connect)
.hidden __connect


ENTRY(listen)
    mov     x8, __NR_listen
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(listen)


ENTRY(__accept4)
    mov     x8, __NR_accept4
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__accept4)
.hidden __accept4


ENTRY(getsockname)
    mov     x8, __NR_getsockname
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getsockname)


ENTRY(getpeername)
    mov     x8, __NR_getpeername
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getpeername)


ENTRY(__sendto)
    mov     x8, __NR_sendto
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__sendto)
.hidden __sendto


ENTRY(recvfrom)
    mov     x8, __NR_recvfrom
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(recvfrom)


ENTRY(shutdown)
    mov     x8, __NR_shutdown
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(shutdown)


ENTRY(setsockopt)
    mov     x8, __NR_setsockopt
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setsockopt)


ENTRY(getsockopt)
    mov     x8, __NR_getsockopt
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getsockopt)


ENTRY(__recvmsg)
    mov     x8, __NR_recvmsg
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__recvmsg)
.hidden __recvmsg


ENTRY(__sendmsg)
    mov     x8, __NR_sendmsg
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__sendmsg)
.hidden __sendmsg


ENTRY(__recvmmsg)
    mov     x8, __NR_recvmmsg
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__recvmmsg)
.hidden __recvmmsg


ENTRY(__sendmmsg)
    mov     x8, __NR_sendmmsg
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__sendmmsg)
.hidden __sendmmsg


ENTRY(sched_setscheduler)
    mov     x8, __NR_sched_setscheduler
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_setscheduler)


ENTRY(sched_getscheduler)
    mov     x8, __NR_sched_getscheduler
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_getscheduler)


ENTRY(sched_yield)
    mov     x8, __NR_sched_yield
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_yield)


ENTRY(sched_setparam)
    mov     x8, __NR_sched_setparam
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_setparam)


ENTRY(sched_getparam)
    mov     x8, __NR_sched_getparam
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_getparam)


ENTRY(sched_get_priority_max)
    mov     x8, __NR_sched_get_priority_max
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_get_priority_max)


ENTRY(sched_get_priority_min)
    mov     x8, __NR_sched_get_priority_min
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_get_priority_min)


ENTRY(sched_rr_get_interval)
    mov     x8, __NR_sched_rr_get_interval
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_rr_get_interval)


ENTRY(sched_setaffinity)
    mov     x8, __NR_sched_setaffinity
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sched_setaffinity)


ENTRY(setns)
    mov     x8, __NR_setns
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setns)


ENTRY(unshare)
    mov     x8, __NR_unshare
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(unshare)


ENTRY(__sched_getaffinity)
    mov     x8, __NR_sched_getaffinity
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__sched_getaffinity)
.hidden __sched_getaffinity


ENTRY(__getcpu)
    mov     x8, __NR_getcpu
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__getcpu)
.hidden __getcpu


ENTRY(uname)
    mov     x8, __NR_uname
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(uname)


ENTRY(umask)
    mov     x8, __NR_umask
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(umask)


ENTRY(__reboot)
    mov     x8, __NR_reboot
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__reboot)
.hidden __reboot


ENTRY(init_module)
    mov     x8, __NR_init_module
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(init_module)


ENTRY(delete_module)
    mov     x8, __NR_delete_module
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(delete_module)


ENTRY(klogctl)
    mov     x8, __NR_syslog
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(klogctl)


ENTRY(sysinfo)
    mov     x8, __NR_sysinfo
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sysinfo)


ENTRY(personality)
    mov     x8, __NR_personality
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(personality)


ENTRY(tee)
    mov     x8, __NR_tee
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(tee)


ENTRY(splice)
    mov     x8, __NR_splice
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(splice)


ENTRY(vmsplice)
    mov     x8, __NR_vmsplice
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(vmsplice)


ENTRY(__epoll_create1)
    mov     x8, __NR_epoll_create1
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__epoll_create1)
.hidden __epoll_create1


ENTRY(epoll_ctl)
    mov     x8, __NR_epoll_ctl
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(epoll_ctl)


ENTRY(__epoll_pwait)
    mov     x8, __NR_epoll_pwait
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__epoll_pwait)
.hidden __epoll_pwait


ENTRY(__eventfd)
    mov     x8, __NR_eventfd2
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__eventfd)
.hidden __eventfd


ENTRY(_exit)
    mov     x8, __NR_exit_group
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(_exit)

ALIAS_SYMBOL(_Exit, _exit)


ENTRY(__exit)
    mov     x8, __NR_exit
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__exit)
.hidden __exit


ENTRY(inotify_init1)
    mov     x8, __NR_inotify_init1
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(inotify_init1)


ENTRY(inotify_add_watch)
    mov     x8, __NR_inotify_add_watch
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(inotify_add_watch)


ENTRY(inotify_rm_watch)
    mov     x8, __NR_inotify_rm_watch
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(inotify_rm_watch)


ENTRY(__pselect6)
    mov     x8, __NR_pselect6
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__pselect6)
.hidden __pselect6


ENTRY(__ppoll)
    mov     x8, __NR_ppoll
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__ppoll)
.hidden __ppoll


ENTRY(process_vm_readv)
    mov     x8, __NR_process_vm_readv
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(process_vm_readv)


ENTRY(process_vm_writev)
    mov     x8, __NR_process_vm_writev
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(process_vm_writev)


ENTRY(quotactl)
    mov     x8, __NR_quotactl
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(quotactl)


ENTRY(__set_tid_address)
    mov     x8, __NR_set_tid_address
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__set_tid_address)
.hidden __set_tid_address


ENTRY(setfsgid)
    mov     x8, __NR_setfsgid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setfsgid)


ENTRY(setfsuid)
    mov     x8, __NR_setfsuid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setfsuid)


ENTRY(setdomainname)
    mov     x8, __NR_setdomainname
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(setdomainname)


ENTRY(sethostname)
    mov     x8, __NR_sethostname
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(sethostname)


ENTRY(__sync_file_range)
    mov     x8, __NR_sync_file_range
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__sync_file_range)
.hidden __sync_file_range


ENTRY(wait4)
    mov     x8, __NR_wait4
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(wait4)


ENTRY(__waitid)
    mov     x8, __NR_waitid
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__waitid)
.hidden __waitid


ENTRY(__clock_getres)
    mov     x8, __NR_clock_getres
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__clock_getres)
.hidden __clock_getres


ENTRY(__clock_gettime)
    mov     x8, __NR_clock_gettime
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__clock_gettime)
.hidden __clock_gettime


ENTRY(__gettimeofday)
    mov     x8, __NR_gettimeofday
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__gettimeofday)
.hidden __gettimeofday


ENTRY(getrandom)
    mov     x8, __NR_getrandom
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(getrandom)


ENTRY(__pidfd_open)
    mov     x8, __NR_pidfd_open
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__pidfd_open)
.hidden __pidfd_open


ENTRY(__pidfd_getfd)
    mov     x8, __NR_pidfd_getfd
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(__pidfd_getfd)
.hidden __pidfd_getfd


ENTRY(pidfd_send_signal)
    mov     x8, __NR_pidfd_send_signal
    svc     #0

    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal

    ret
END(pidfd_send_signal)


NOTE_GNU_PROPERTY()

