// SPDX-License-Identifier: GPL-2.0+
/*
 * erofs-utils/fuse/main.c
 *
 * Created by Li Guifu <blucerlee@gmail.com>
 */
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <libgen.h>
#include <fuse.h>
#include <fuse_opt.h>

#include "erofs/config.h"
#include "erofs/print.h"
#include "erofs/io.h"

int erofsfuse_readdir(const char *path, void *buffer, fuse_fill_dir_t filler,
		      off_t offset, struct fuse_file_info *fi);

static void *erofsfuse_init(struct fuse_conn_info *info)
{
	erofs_info("Using FUSE protocol %d.%d", info->proto_major, info->proto_minor);
	return NULL;
}

static int erofsfuse_open(const char *path, struct fuse_file_info *fi)
{
	erofs_dbg("open path=%s", path);

	if ((fi->flags & O_ACCMODE) != O_RDONLY)
		return -EACCES;

	return 0;
}

static int erofsfuse_getattr(const char *path, struct stat *stbuf)
{
	struct erofs_inode vi = {};
	int ret;

	erofs_dbg("getattr(%s)", path);
	ret = erofs_ilookup(path, &vi);
	if (ret)
		return -ENOENT;

	stbuf->st_mode  = vi.i_mode;
	stbuf->st_nlink = vi.i_nlink;
	stbuf->st_size  = vi.i_size;
	stbuf->st_blocks = roundup(vi.i_size, EROFS_BLKSIZ) >> 9;
	stbuf->st_uid = vi.i_uid;
	stbuf->st_gid = vi.i_gid;
	if (S_ISBLK(vi.i_mode) || S_ISCHR(vi.i_mode))
		stbuf->st_rdev = vi.u.i_rdev;
	stbuf->st_ctime = vi.i_ctime;
	stbuf->st_mtime = stbuf->st_ctime;
	stbuf->st_atime = stbuf->st_ctime;
	return 0;
}

static int erofsfuse_read(const char *path, char *buffer,
			  size_t size, off_t offset,
			  struct fuse_file_info *fi)
{
	int ret;
	struct erofs_inode vi;

	erofs_dbg("path:%s size=%zd offset=%llu", path, size, (long long)offset);

	ret = erofs_ilookup(path, &vi);
	if (ret)
		return ret;

	ret = erofs_pread(&vi, buffer, size, offset);
	if (ret)
		return ret;
	return size;
}

static int erofsfuse_readlink(const char *path, char *buffer, size_t size)
{
	int ret = erofsfuse_read(path, buffer, size, 0, NULL);

	if (ret < 0)
		return ret;
	return 0;
}

static struct fuse_operations erofs_ops = {
	.readlink = erofsfuse_readlink,
	.getattr = erofsfuse_getattr,
	.readdir = erofsfuse_readdir,
	.open = erofsfuse_open,
	.read = erofsfuse_read,
	.init = erofsfuse_init,
};

static struct options {
	const char *disk;
	const char *mountpoint;
	unsigned int debug_lvl;
	bool show_help;
	bool odebug;
} fusecfg;

#define OPTION(t, p)                           \
    { t, offsetof(struct options, p), 1 }
static const struct fuse_opt option_spec[] = {
	OPTION("--dbglevel=%u", debug_lvl),
	OPTION("--help", show_help),
	FUSE_OPT_END
};

#define OPTION(t, p)    { t, offsetof(struct options, p), 1 }

static void usage(void)
{
	struct fuse_args args = FUSE_ARGS_INIT(0, NULL);

	fputs("usage: [options] IMAGE MOUNTPOINT\n\n"
	      "Options:\n"
	      "    --dbglevel=#           set output message level to # (maximum 9)\n"
#if FUSE_MAJOR_VERSION < 3
	      "    --help                 display this help and exit\n"
#endif
	      "\n", stderr);

#if FUSE_MAJOR_VERSION >= 3
	fuse_cmdline_help();
#else
	fuse_opt_add_arg(&args, ""); /* progname */
	fuse_opt_add_arg(&args, "-ho"); /* progname */
	fuse_parse_cmdline(&args, NULL, NULL, NULL);
#endif
	exit(EXIT_FAILURE);
}

static void erofsfuse_dumpcfg(void)
{
	erofs_dump("disk: %s\n", fusecfg.disk);
	erofs_dump("mountpoint: %s\n", fusecfg.mountpoint);
	erofs_dump("dbglevel: %u\n", cfg.c_dbg_lvl);
}

static int optional_opt_func(void *data, const char *arg, int key,
			     struct fuse_args *outargs)
{
	switch (key) {
	case FUSE_OPT_KEY_NONOPT:
		if (fusecfg.mountpoint)
			return -1; /* Too many args */

		if (!fusecfg.disk) {
			fusecfg.disk = strdup(arg);
			return 0;
		}
		if (!fusecfg.mountpoint)
			fusecfg.mountpoint = strdup(arg);
	case FUSE_OPT_KEY_OPT:
		if (!strcmp(arg, "-d"))
			fusecfg.odebug = true;
		break;
	default:
		DBG_BUGON(1);
		break;
	}
	return 1;
}

#if defined(HAVE_EXECINFO_H) && defined(HAVE_BACKTRACE)
#include <execinfo.h>

static void signal_handle_sigsegv(int signal)
{
	void *array[10];
	size_t nptrs;
	char **strings;
	size_t i;

	erofs_dump("========================================\n");
	erofs_dump("Segmentation Fault.  Starting backtrace:\n");
	nptrs = backtrace(array, 10);
	strings = backtrace_symbols(array, nptrs);
	if (strings) {
		for (i = 0; i < nptrs; i++)
			erofs_dump("%s\n", strings[i]);
		free(strings);
	}
	erofs_dump("========================================\n");
	abort();
}
#endif

int main(int argc, char *argv[])
{
	int ret;
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

	erofs_init_configure();
	fprintf(stderr, "%s %s\n", basename(argv[0]), cfg.c_version);

#if defined(HAVE_EXECINFO_H) && defined(HAVE_BACKTRACE)
	if (signal(SIGSEGV, signal_handle_sigsegv) == SIG_ERR) {
		fprintf(stderr, "failed to initialize signals\n");
		ret = -errno;
		goto err;
	}
#endif

	/* parse options */
	ret = fuse_opt_parse(&args, &fusecfg, option_spec, optional_opt_func);
	if (ret)
		goto err;

	if (fusecfg.show_help || !fusecfg.mountpoint)
		usage();
	cfg.c_dbg_lvl = fusecfg.debug_lvl;

	if (fusecfg.odebug && cfg.c_dbg_lvl < EROFS_DBG)
		cfg.c_dbg_lvl = EROFS_DBG;

	erofsfuse_dumpcfg();
	ret = dev_open_ro(fusecfg.disk);
	if (ret) {
		fprintf(stderr, "failed to open: %s\n", fusecfg.disk);
		goto err_fuse_free_args;
	}

	ret = erofs_read_superblock();
	if (ret) {
		fprintf(stderr, "failed to read erofs super block\n");
		goto err_dev_close;
	}

	ret = fuse_main(args.argc, args.argv, &erofs_ops, NULL);
err_dev_close:
	dev_close();
err_fuse_free_args:
	fuse_opt_free_args(&args);
err:
	erofs_exit_configure();
	return ret ? EXIT_FAILURE : EXIT_SUCCESS;
}

