/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "private/ErrnoRestorer.h"

static FILE* __fd_to_fp(int fd) {
  FILE* fp = fdopen(fd, "w+");
  if (fp != nullptr) return fp;

  ErrnoRestorer errno_restorer;
  close(fd);
  return nullptr;
}

static FILE* __tmpfile_dir_legacy(const char* tmp_dir) {
  char* path = nullptr;
  if (asprintf(&path, "%s/tmp.XXXXXXXXXX", tmp_dir) == -1) {
    return nullptr;
  }

  int fd = mkstemp(path);
  if (fd == -1) {
    free(path);
    return nullptr;
  }

  // Unlink the file now so that it's removed when closed.
  unlink(path);
  free(path);

  // Can we still use the file now it's unlinked?
  // File systems without hard link support won't have the usual Unix semantics.
  struct stat sb;
  if (fstat(fd, &sb) == -1) {
    ErrnoRestorer errno_restorer;
    close(fd);
    return nullptr;
  }

  return __fd_to_fp(fd);
}

static FILE* __tmpfile_dir(const char* tmp_dir) {
  int fd = open(tmp_dir, O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1) return __tmpfile_dir_legacy(tmp_dir);
  return __fd_to_fp(fd);
}

FILE* tmpfile() {
  // TODO: get this app's temporary directory from the framework ("/data/data/app/cache").

  // $EXTERNAL_STORAGE turns out not to be very useful because it doesn't support hard links.
  // This means we can't do the usual trick of calling unlink before handing the file back.

  FILE* fp = __tmpfile_dir("/data/local/tmp");
  if (fp == nullptr) {
    // P_tmpdir is "/tmp/", but POSIX explicitly says that tmpdir(3) should try P_tmpdir before
    // giving up. This is potentially useful for bionic on the host anyway.
    fp = __tmpfile_dir(P_tmpdir);
  }
  return fp;
}
__strong_alias(tmpfile64, tmpfile);

char* tempnam(const char* dir, const char* prefix) {
  // This function is a terrible idea, marked deprecated in our headers,
  // and marked obsolescent by POSIX.1-2008, but we make some effort anyway
  // since we can't easily remove it...

  // $TMPDIR overrides any directory passed in.
  char* tmpdir = getenv("TMPDIR");
  if (tmpdir != nullptr) dir = tmpdir;

  // If we still have no directory, we'll give you a default.
  // It's useless for apps, but good enough for the shell.
  if (dir == nullptr) dir = "/data/local/tmp";

  // Default prefix?
  if (prefix == nullptr) prefix = "tempnam.";

  // Make up a mktemp(3) template and defer to it for the real work.
  char* path = nullptr;
  if (asprintf(&path, "%s/%sXXXXXXXXXX", dir, prefix) == -1) return nullptr;
  if (mktemp(path) == nullptr) {
    free(path);
    return nullptr;
  }
  return path;
}

char* tmpnam(char* s) {
  // This function is a terrible idea, marked deprecated in our headers,
  // and marked obsolescent by POSIX-1.2008, but we make some effort anyway
  // since we can't easily remove it...

  // Default buffer?
  static char buf[L_tmpnam];
  if (s == nullptr) s = buf;

  // Use $TMPDIR if set, or fall back to /data/local/tmp otherwise.
  // Useless for apps, but good enough for the shell.
  const char* dir = getenv("TMPDIR");
  if (dir == nullptr) dir = "/data/local/tmp";

  // Make up a mktemp(3) template and defer to it for the real work.
  snprintf(s, L_tmpnam, "%s/tmpnam.XXXXXXXXXX", dir);
  return mktemp(s);
}
