/**************************************************************************
 *
 * Copyright (C) 2020 Chromium
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#include "virgl_resource.h"

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "util/u_hash_table.h"
#include "util/u_pointer.h"
#include "virgl_util.h"

static struct util_hash_table *virgl_resource_table;
static struct virgl_resource_pipe_callbacks pipe_callbacks;

static void
virgl_resource_destroy_func(void *val)
{
   struct virgl_resource *res = (struct virgl_resource *)val;

   if (res->pipe_resource)
      pipe_callbacks.unref(res->pipe_resource, pipe_callbacks.data);
   if (res->fd_type != VIRGL_RESOURCE_FD_INVALID)
      close(res->fd);

   free(res);
}

int
virgl_resource_table_init(const struct virgl_resource_pipe_callbacks *callbacks)
{
   virgl_resource_table = util_hash_table_create(hash_func_u32,
                                                 compare_func,
                                                 virgl_resource_destroy_func);
   if (!virgl_resource_table)
      return ENOMEM;

   pipe_callbacks = *callbacks;

   return 0;
}

void
virgl_resource_table_cleanup(void)
{
   util_hash_table_destroy(virgl_resource_table);
   memset(&pipe_callbacks, 0, sizeof(pipe_callbacks));
}

void
virgl_resource_table_reset(void)
{
   util_hash_table_clear(virgl_resource_table);
}

static struct virgl_resource *
virgl_resource_create(uint32_t res_id)
{
   struct virgl_resource *res;
   enum pipe_error err;

   res = calloc(1, sizeof(*res));
   if (!res)
      return NULL;

   err = util_hash_table_set(virgl_resource_table,
                             uintptr_to_pointer(res_id),
                             res);
   if (err != PIPE_OK) {
      free(res);
      return NULL;
   }

   res->res_id = res_id;
   res->fd_type = VIRGL_RESOURCE_FD_INVALID;
   res->fd = -1;

   return res;
}

struct virgl_resource *
virgl_resource_create_from_pipe(uint32_t res_id,
                                struct pipe_resource *pres,
                                const struct iovec *iov,
                                int iov_count)
{
   struct virgl_resource *res;

   res = virgl_resource_create(res_id);
   if (!res)
      return NULL;

   /* take ownership */
   res->pipe_resource = pres;

   res->iov = iov;
   res->iov_count = iov_count;

   return res;
}

struct virgl_resource *
virgl_resource_create_from_fd(uint32_t res_id,
                              enum virgl_resource_fd_type fd_type,
                              int fd,
                              const struct iovec *iov,
                              int iov_count)
{
   struct virgl_resource *res;

   assert(fd_type != VIRGL_RESOURCE_FD_INVALID  && fd >= 0);

   res = virgl_resource_create(res_id);
   if (!res)
      return NULL;

   res->fd_type = fd_type;
   /* take ownership */
   res->fd = fd;

   res->iov = iov;
   res->iov_count = iov_count;

   return res;
}

struct virgl_resource *
virgl_resource_create_from_iov(uint32_t res_id,
                               const struct iovec *iov,
                               int iov_count)
{
   struct virgl_resource *res;

   if (iov_count)
      assert(iov);

   res = virgl_resource_create(res_id);
   if (!res)
      return NULL;

   res->iov = iov;
   res->iov_count = iov_count;

   return res;
}

void
virgl_resource_remove(uint32_t res_id)
{
   util_hash_table_remove(virgl_resource_table, uintptr_to_pointer(res_id));
}

struct virgl_resource *virgl_resource_lookup(uint32_t res_id)
{
   return util_hash_table_get(virgl_resource_table,
                              uintptr_to_pointer(res_id));
}

int
virgl_resource_attach_iov(struct virgl_resource *res,
                          const struct iovec *iov,
                          int iov_count)
{
   if (res->iov)
      return EINVAL;

   res->iov = iov;
   res->iov_count = iov_count;

   if (res->pipe_resource) {
      pipe_callbacks.attach_iov(res->pipe_resource,
                                iov,
                                iov_count,
                                pipe_callbacks.data);
   }

   return 0;
}

void
virgl_resource_detach_iov(struct virgl_resource *res)
{
   if (!res->iov)
      return;

   if (res->pipe_resource)
      pipe_callbacks.detach_iov(res->pipe_resource, pipe_callbacks.data);

   res->iov = NULL;
   res->iov_count = 0;
}

enum virgl_resource_fd_type
virgl_resource_export_fd(struct virgl_resource *res, int *fd)
{
   if (res->fd_type != VIRGL_RESOURCE_FD_INVALID) {
#ifdef F_DUPFD_CLOEXEC
      *fd = fcntl(res->fd, F_DUPFD_CLOEXEC, 0);
      if (*fd < 0)
         *fd = dup(res->fd);
#else
      *fd = dup(res->fd);
#endif
      return *fd >= 0 ? res->fd_type : VIRGL_RESOURCE_FD_INVALID;
   } else if (res->pipe_resource) {
      return pipe_callbacks.export_fd(res->pipe_resource,
                                      fd,
                                      pipe_callbacks.data);
   }

   return VIRGL_RESOURCE_FD_INVALID;
}
