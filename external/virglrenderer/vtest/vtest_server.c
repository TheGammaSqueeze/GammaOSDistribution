/**************************************************************************
 *
 * Copyright (C) 2015 Red Hat Inc.
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
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <fcntl.h>
#include <getopt.h>
#include <string.h>

#include "util.h"
#include "util/u_double_list.h"
#include "util/u_math.h"
#include "util/u_memory.h"
#include "vtest.h"
#include "vtest_protocol.h"
#include "virglrenderer.h"
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

enum vtest_client_error {
   VTEST_CLIENT_ERROR_INPUT_READ = 2, /* for backward compatibility */
   VTEST_CLIENT_ERROR_CONTEXT_MISSING,
   VTEST_CLIENT_ERROR_CONTEXT_FAILED,
   VTEST_CLIENT_ERROR_COMMAND_ID,
   VTEST_CLIENT_ERROR_COMMAND_UNEXPECTED,
   VTEST_CLIENT_ERROR_COMMAND_DISPATCH,
};

struct vtest_client
{
   int in_fd;
   int out_fd;
   struct vtest_input input;

   struct list_head head;

   bool in_fd_ready;
   struct vtest_context *context;
};

struct vtest_server
{
   const char *socket_name;
   int socket;
   const char *read_file;

   const char *render_device;

   bool main_server;
   bool do_fork;
   bool loop;
   bool multi_clients;

   bool use_glx;
   bool use_egl_surfaceless;
   bool use_gles;

   int ctx_flags;

   struct list_head new_clients;
   struct list_head active_clients;
   struct list_head inactive_clients;
};

struct vtest_server server = {
   .socket_name = VTEST_DEFAULT_SOCKET_NAME,
   .socket = -1,

   .read_file = NULL,

   .render_device = 0,

   .main_server = true,
   .do_fork = true,
   .loop = true,
   .multi_clients = false,

   .ctx_flags = 0,
};

static void vtest_server_getenv(void);
static void vtest_server_parse_args(int argc, char **argv);
static void vtest_server_set_signal_child(void);
static void vtest_server_set_signal_segv(void);
static void vtest_server_open_read_file(void);
static void vtest_server_open_socket(void);
static void vtest_server_run(void);
static void vtest_server_close_socket(void);
static int vtest_client_dispatch_commands(struct vtest_client *client);


int main(int argc, char **argv)
{
#ifdef __AFL_LOOP
while (__AFL_LOOP(1000)) {
#endif

   vtest_server_getenv();
   vtest_server_parse_args(argc, argv);

   list_inithead(&server.new_clients);
   list_inithead(&server.active_clients);
   list_inithead(&server.inactive_clients);

   if (server.do_fork) {
      vtest_server_set_signal_child();
   } else {
      vtest_server_set_signal_segv();
   }

   vtest_server_run();

#ifdef __AFL_LOOP
   if (!server.main_server) {
      exit(0);
   }
}
#endif
}

#define OPT_NO_FORK 'f'
#define OPT_NO_LOOP_OR_FORK 'l'
#define OPT_MULTI_CLIENTS 'm'
#define OPT_USE_GLX 'x'
#define OPT_USE_EGL_SURFACELESS 's'
#define OPT_USE_GLES 'e'
#define OPT_RENDERNODE 'r'

static void vtest_server_parse_args(int argc, char **argv)
{
   int ret;

   static struct option long_options[] = {
      {"no-fork",             no_argument, NULL, OPT_NO_FORK},
      {"no-loop-or-fork",     no_argument, NULL, OPT_NO_LOOP_OR_FORK},
      {"multi-clients",       no_argument, NULL, OPT_MULTI_CLIENTS},
      {"use-glx",             no_argument, NULL, OPT_USE_GLX},
      {"use-egl-surfaceless", no_argument, NULL, OPT_USE_EGL_SURFACELESS},
      {"use-gles",            no_argument, NULL, OPT_USE_GLES},
      {"rendernode",          required_argument, NULL, OPT_RENDERNODE},
      {0, 0, 0, 0}
   };

   /* getopt_long stores the option index here. */
   int option_index = 0;

   do {
      ret = getopt_long(argc, argv, "", long_options, &option_index);

      switch (ret) {
      case -1:
         break;
      case OPT_NO_FORK:
         server.do_fork = false;
         break;
      case OPT_NO_LOOP_OR_FORK:
         server.do_fork = false;
         server.loop = false;
         break;
      case OPT_MULTI_CLIENTS:
         printf("EXPERIMENTAL: clients must know and trust each other\n");
         server.multi_clients = true;
         break;
      case OPT_USE_GLX:
         server.use_glx = true;
         break;
      case OPT_USE_EGL_SURFACELESS:
         server.use_egl_surfaceless = true;
         break;
      case OPT_USE_GLES:
         server.use_gles = true;
         break;
      case OPT_RENDERNODE:
         server.render_device = optarg;
         break;
      default:
         printf("Usage: %s [--no-fork] [--no-loop-or-fork] [--multi-clients] "
                "[--use-glx] [--use-egl-surfaceless] [--use-gles] "
                "[--rendernode <dev>]"
                " [file]\n", argv[0]);
         exit(EXIT_FAILURE);
         break;
      }

   } while (ret >= 0);

   if (optind < argc) {
      server.read_file = argv[optind];
      server.loop = false;
      server.do_fork = false;
      server.multi_clients = false;
   }

   server.ctx_flags = VIRGL_RENDERER_USE_EGL;
   if (server.use_glx) {
      if (server.use_egl_surfaceless || server.use_gles) {
         fprintf(stderr, "Cannot use surfaceless or GLES with GLX.\n");
         exit(EXIT_FAILURE);
      }
      server.ctx_flags = VIRGL_RENDERER_USE_GLX;
   } else {
      if (server.use_egl_surfaceless)
         server.ctx_flags |= VIRGL_RENDERER_USE_SURFACELESS;
      if (server.use_gles)
         server.ctx_flags |= VIRGL_RENDERER_USE_GLES;
   }
}

static void vtest_server_getenv(void)
{
   server.use_glx = getenv("VTEST_USE_GLX") != NULL;
   server.use_egl_surfaceless = getenv("VTEST_USE_EGL_SURFACELESS") != NULL;
   server.use_gles = getenv("VTEST_USE_GLES") != NULL;
   server.render_device = getenv("VTEST_RENDERNODE");
}

static void handler(int sig, siginfo_t *si, void *unused)
{
   (void)sig; (void)si, (void)unused;

   printf("SIGSEGV!\n");
   exit(EXIT_FAILURE);
}

static void vtest_server_set_signal_child(void)
{
   struct sigaction sa;
   int ret;

   memset(&sa, 0, sizeof(sa));
   sigemptyset(&sa.sa_mask);
   sa.sa_handler = SIG_IGN;
   sa.sa_flags = 0;

   ret = sigaction(SIGCHLD, &sa, NULL);
   if (ret == -1) {
      perror("Failed to set SIGCHLD");
      exit(1);
   }
}

static void vtest_server_set_signal_segv(void)
{
   struct sigaction sa;
   int ret;

   memset(&sa, 0, sizeof(sa));
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = handler;

   ret = sigaction(SIGSEGV, &sa, NULL);
   if (ret == -1) {
      perror("Failed to set SIGSEGV");
      exit(1);
   }
}

static int vtest_server_add_client(int in_fd, int out_fd)
{
   struct vtest_client *client;

   client = calloc(1, sizeof(*client));
   if (!client)
      return -1;

   client->in_fd = in_fd;
   client->out_fd = out_fd;

   client->input.data.fd = in_fd;
   client->input.read = vtest_block_read;

   list_addtail(&client->head, &server.new_clients);

   return 0;
}

static void vtest_server_open_read_file(void)
{
   int in_fd;
   int out_fd;

   in_fd = open(server.read_file, O_RDONLY);
   if (in_fd == -1) {
      perror(NULL);
      exit(1);
   }

   out_fd = open("/dev/null", O_WRONLY);
   if (out_fd == -1) {
      perror(NULL);
      exit(1);
   }

   if (vtest_server_add_client(in_fd, out_fd)) {
      perror(NULL);
      exit(1);
   }
}

static void vtest_server_open_socket(void)
{
   struct sockaddr_un un;

   server.socket = socket(PF_UNIX, SOCK_STREAM, 0);
   if (server.socket < 0) {
      goto err;
   }

   memset(&un, 0, sizeof(un));
   un.sun_family = AF_UNIX;

   snprintf(un.sun_path, sizeof(un.sun_path), "%s", server.socket_name);

   unlink(un.sun_path);

   if (bind(server.socket, (struct sockaddr *)&un, sizeof(un)) < 0) {
      goto err;
   }

   if (listen(server.socket, 1) < 0){
      goto err;
   }

   return;

err:
   perror("Failed to setup socket.");
   exit(1);
}

static void vtest_server_wait_clients(void)
{
   struct vtest_client *client;
   fd_set read_fds;
   int max_fd = -1;
   int ret;

   FD_ZERO(&read_fds);

   LIST_FOR_EACH_ENTRY(client, &server.active_clients, head) {
      FD_SET(client->in_fd, &read_fds);
      max_fd = MAX2(client->in_fd, max_fd);
   }

   /* accept new clients when there is none or when multi_clients is set */
   if (server.socket >= 0 && (max_fd < 0 || server.multi_clients)) {
      FD_SET(server.socket, &read_fds);
      max_fd = MAX2(server.socket, max_fd);
   }

   if (max_fd < 0) {
      if (!LIST_IS_EMPTY(&server.new_clients)) {
         return;
      }

      fprintf(stderr, "server has no fd to wait\n");
      exit(1);
   }

   ret = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
   if (ret < 0) {
      perror("Failed to select on socket!");
      exit(1);
   }

   LIST_FOR_EACH_ENTRY(client, &server.active_clients, head) {
      if (FD_ISSET(client->in_fd, &read_fds)) {
         client->in_fd_ready = true;
      }
   }

   if (server.socket >= 0 && FD_ISSET(server.socket, &read_fds)) {
      int new_fd = accept(server.socket, NULL, NULL);
      if (new_fd < 0) {
         perror("Failed to accept socket.");
         exit(1);
      }

      if (vtest_server_add_client(new_fd, new_fd)) {
         perror("Failed to add client.");
         exit(1);
      }
   }
}

static const char *vtest_client_error_string(enum vtest_client_error err)
{
   switch (err) {
#define CASE(e) case e: return #e;
   CASE(VTEST_CLIENT_ERROR_INPUT_READ)
   CASE(VTEST_CLIENT_ERROR_CONTEXT_MISSING)
   CASE(VTEST_CLIENT_ERROR_CONTEXT_FAILED)
   CASE(VTEST_CLIENT_ERROR_COMMAND_ID)
   CASE(VTEST_CLIENT_ERROR_COMMAND_UNEXPECTED)
   CASE(VTEST_CLIENT_ERROR_COMMAND_DISPATCH)
#undef CASE
   default: return "VTEST_CLIENT_ERROR_UNKNOWN";
   }
}

static void vtest_server_dispatch_clients(void)
{
   struct vtest_client *client, *tmp;

   LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.active_clients, head) {
      int err;

      if (!client->in_fd_ready)
         continue;
      client->in_fd_ready = false;

      err = vtest_client_dispatch_commands(client);
      if (err) {
         fprintf(stderr, "client failed: %s\n",
                 vtest_client_error_string(err));
         list_del(&client->head);
         list_addtail(&client->head, &server.inactive_clients);
      }
   }
}

static pid_t vtest_server_fork(void)
{
   pid_t pid = fork();

   if (pid == 0) {
      /* child */
      vtest_server_set_signal_segv();
      vtest_server_close_socket();
      server.main_server = false;
      server.do_fork = false;
      server.loop = false;
      server.multi_clients = false;
   }

   return pid;
}

static void vtest_server_fork_clients(void)
{
   struct vtest_client *client, *tmp;

   LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.new_clients, head) {
      if (vtest_server_fork()) {
         /* parent: move new clients to the inactive list */
         list_del(&client->head);
         list_addtail(&client->head, &server.inactive_clients);
      } else {
         /* child: move the first new client to the active list */
         list_del(&client->head);
         list_addtail(&client->head, &server.active_clients);

         /* move the rest new clients to the inactive list */
         LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.new_clients, head) {
            list_del(&client->head);
            list_addtail(&client->head, &server.inactive_clients);
         }
      }
   }
}

static void vtest_server_activate_clients(void)
{
   struct vtest_client *client, *tmp;

   /* move new clients to the active list */
   LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.new_clients, head) {
      list_addtail(&client->head, &server.active_clients);
   }
   list_inithead(&server.new_clients);
}

static void vtest_server_inactivate_clients(void)
{
   struct vtest_client *client, *tmp;

   /* move active clients to the inactive list */
   LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.active_clients, head) {
      list_addtail(&client->head, &server.inactive_clients);
   }
   list_inithead(&server.active_clients);
}

static void vtest_server_tidy_clients(void)
{
   struct vtest_client *client, *tmp;

   LIST_FOR_EACH_ENTRY_SAFE(client, tmp, &server.inactive_clients, head) {
      if (client->context) {
         vtest_destroy_context(client->context);
      }

      if (client->in_fd >= 0) {
         close(client->in_fd);
      }

      if (client->out_fd >= 0 && client->out_fd != client->in_fd) {
         close(client->out_fd);
      }

      free(client);
   }

   list_inithead(&server.inactive_clients);
}

static void vtest_server_run(void)
{
   bool run = true;

   if (server.read_file) {
      vtest_server_open_read_file();
   } else {
      vtest_server_open_socket();
   }

   while (run) {
      const bool was_empty = LIST_IS_EMPTY(&server.active_clients);
      bool is_empty;

      vtest_server_wait_clients();
      vtest_server_dispatch_clients();

      if (server.do_fork) {
         vtest_server_fork_clients();
      } else {
         vtest_server_activate_clients();
      }

      /* init renderer after the first active client is added */
      is_empty = LIST_IS_EMPTY(&server.active_clients);
      if (was_empty && !is_empty) {
         int ret = vtest_init_renderer(server.ctx_flags, server.render_device);
         if (ret) {
            vtest_server_inactivate_clients();
            run = false;
         }
      }

      vtest_server_tidy_clients();

      /* clean up renderer after the last active client is removed */
      if (!was_empty && is_empty) {
         vtest_cleanup_renderer();
         if (!server.loop) {
            run = false;
         }
      }
   }

   vtest_server_close_socket();
}

static const struct vtest_command {
   int (*dispatch)(uint32_t);
   bool init_context;
} vtest_commands[] = {
   /* CMD ids starts at 1 */
   [0]                          = { NULL,                        false },
   [VCMD_GET_CAPS]              = { vtest_send_caps,             false },
   [VCMD_RESOURCE_CREATE]       = { vtest_create_resource,       true  },
   [VCMD_RESOURCE_UNREF]        = { vtest_resource_unref,        true  },
   [VCMD_TRANSFER_GET]          = { vtest_transfer_get,          true  },
   [VCMD_TRANSFER_PUT]          = { vtest_transfer_put,          true  },
   [VCMD_SUBMIT_CMD]            = { vtest_submit_cmd,            true  },
   [VCMD_RESOURCE_BUSY_WAIT]    = { vtest_resource_busy_wait,    false },
   /* VCMD_CREATE_RENDERER is a special case */
   [VCMD_CREATE_RENDERER]       = { NULL,                        false },
   [VCMD_GET_CAPS2]             = { vtest_send_caps2,            false },
   [VCMD_PING_PROTOCOL_VERSION] = { vtest_ping_protocol_version, false },
   [VCMD_PROTOCOL_VERSION]      = { vtest_protocol_version,      false },

   /* since protocol version 2 */
   [VCMD_RESOURCE_CREATE2]      = { vtest_create_resource2,      true  },
   [VCMD_TRANSFER_GET2]         = { vtest_transfer_get2,         true  },
   [VCMD_TRANSFER_PUT2]         = { vtest_transfer_put2,         true  },

   /* since protocol version 3 */
   [VCMD_GET_PARAM]             = { vtest_get_param,             false },
   [VCMD_GET_CAPSET]            = { vtest_get_capset,            false },
   [VCMD_CONTEXT_INIT]          = { vtest_context_init,          false },
};

static int vtest_client_dispatch_commands(struct vtest_client *client)
{
   const struct vtest_command *cmd;
   int ret;
   uint32_t header[VTEST_HDR_SIZE];

   ret = client->input.read(&client->input, &header, sizeof(header));
   if (ret < 0 || (size_t)ret < sizeof(header)) {
      return VTEST_CLIENT_ERROR_INPUT_READ;
   }

   if (!client->context) {
      /* The first command MUST be VCMD_CREATE_RENDERER */
      if (header[1] != VCMD_CREATE_RENDERER) {
         return VTEST_CLIENT_ERROR_CONTEXT_MISSING;
      }

      ret = vtest_create_context(&client->input, client->out_fd,
                                 header[0], &client->context);
      if (ret < 0) {
         return VTEST_CLIENT_ERROR_CONTEXT_FAILED;
      }
      printf("%s: client context created.\n", __func__);
      vtest_poll();

      return 0;
   }

   vtest_poll();
   if (header[1] <= 0 || header[1] >= ARRAY_SIZE(vtest_commands)) {
      return VTEST_CLIENT_ERROR_COMMAND_ID;
   }

   cmd = &vtest_commands[header[1]];
   if (cmd->dispatch == NULL) {
      return VTEST_CLIENT_ERROR_COMMAND_UNEXPECTED;
   }

   /* we should consider per-context dispatch table to get rid of if's */
   if (cmd->init_context) {
      ret = vtest_lazy_init_context(client->context);
      if (ret) {
         return VTEST_CLIENT_ERROR_CONTEXT_FAILED;
      }
   }

   vtest_set_current_context(client->context);

   ret = cmd->dispatch(header[0]);
   if (ret < 0) {
      return VTEST_CLIENT_ERROR_COMMAND_DISPATCH;
   }

   /* GL draws are fenced, while possible fence creations are too */
   if (header[1] == VCMD_SUBMIT_CMD || header[1] == VCMD_RESOURCE_CREATE ||
       header[1] == VCMD_RESOURCE_CREATE2)
      vtest_renderer_create_fence();

   return 0;
}

static void vtest_server_close_socket(void)
{
   if (server.socket != -1) {
      close(server.socket);
      server.socket = -1;
   }
}
