// SPDX-License-Identifier: GPL-2.0+
/*
 * erofs-utils/lib/cache.c
 *
 * Copyright (C) 2018-2019 HUAWEI, Inc.
 *             http://www.huawei.com/
 * Created by Miao Xie <miaoxie@huawei.com>
 * with heavy changes by Gao Xiang <gaoxiang25@huawei.com>
 */
#include <stdlib.h>
#include <erofs/cache.h>
#include "erofs/io.h"
#include "erofs/print.h"

static struct erofs_buffer_block blkh = {
	.list = LIST_HEAD_INIT(blkh.list),
	.blkaddr = NULL_ADDR,
};
static erofs_blk_t tail_blkaddr;

static bool erofs_bh_flush_drop_directly(struct erofs_buffer_head *bh)
{
	return erofs_bh_flush_generic_end(bh);
}

struct erofs_bhops erofs_drop_directly_bhops = {
	.flush = erofs_bh_flush_drop_directly,
};

static bool erofs_bh_flush_skip_write(struct erofs_buffer_head *bh)
{
	return false;
}

struct erofs_bhops erofs_skip_write_bhops = {
	.flush = erofs_bh_flush_skip_write,
};

int erofs_bh_flush_generic_write(struct erofs_buffer_head *bh, void *buf)
{
	struct erofs_buffer_head *nbh = list_next_entry(bh, list);
	erofs_off_t offset = erofs_btell(bh, false);

	DBG_BUGON(nbh->off < bh->off);
	return dev_write(buf, offset, nbh->off - bh->off);
}

static bool erofs_bh_flush_buf_write(struct erofs_buffer_head *bh)
{
	int err = erofs_bh_flush_generic_write(bh, bh->fsprivate);

	if (err)
		return false;
	free(bh->fsprivate);
	return erofs_bh_flush_generic_end(bh);
}

struct erofs_bhops erofs_buf_write_bhops = {
	.flush = erofs_bh_flush_buf_write,
};

/* return buffer_head of erofs super block (with size 0) */
struct erofs_buffer_head *erofs_buffer_init(void)
{
	struct erofs_buffer_head *bh = erofs_balloc(META, 0, 0, 0);

	if (IS_ERR(bh))
		return bh;

	bh->op = &erofs_skip_write_bhops;
	return bh;
}

/* return occupied bytes in specific buffer block if succeed */
static int __erofs_battach(struct erofs_buffer_block *bb,
			   struct erofs_buffer_head *bh,
			   erofs_off_t incr,
			   unsigned int alignsize,
			   unsigned int extrasize,
			   bool dryrun)
{
	const erofs_off_t alignedoffset = roundup(bb->buffers.off, alignsize);
	const int oob = cmpsgn(roundup(bb->buffers.off % EROFS_BLKSIZ,
				       alignsize) + incr + extrasize,
			       EROFS_BLKSIZ);
	bool tailupdate = false;
	erofs_blk_t blkaddr;

	if (oob >= 0) {
		/* the next buffer block should be NULL_ADDR all the time */
		if (oob && list_next_entry(bb, list)->blkaddr != NULL_ADDR)
			return -EINVAL;

		blkaddr = bb->blkaddr;
		if (blkaddr != NULL_ADDR) {
			tailupdate = (tail_blkaddr == blkaddr +
				      BLK_ROUND_UP(bb->buffers.off));
			if (oob && !tailupdate)
				return -EINVAL;
		}
	}

	if (!dryrun) {
		if (bh) {
			bh->off = alignedoffset;
			bh->block = bb;
			list_add_tail(&bh->list, &bb->buffers.list);
		}
		bb->buffers.off = alignedoffset + incr;
		/* need to update the tail_blkaddr */
		if (tailupdate)
			tail_blkaddr = blkaddr + BLK_ROUND_UP(bb->buffers.off);
	}
	return (alignedoffset + incr) % EROFS_BLKSIZ;
}

int erofs_bh_balloon(struct erofs_buffer_head *bh, erofs_off_t incr)
{
	struct erofs_buffer_block *const bb = bh->block;

	/* should be the tail bh in the corresponding buffer block */
	if (bh->list.next != &bb->buffers.list)
		return -EINVAL;

	return __erofs_battach(bb, NULL, incr, 1, 0, false);
}

struct erofs_buffer_head *erofs_balloc(int type, erofs_off_t size,
				       unsigned int required_ext,
				       unsigned int inline_ext)
{
	struct erofs_buffer_block *cur, *bb;
	struct erofs_buffer_head *bh;
	unsigned int alignsize, used0, usedmax;

	int ret = get_alignsize(type, &type);

	if (ret < 0)
		return ERR_PTR(ret);
	alignsize = ret;

	used0 = (size + required_ext) % EROFS_BLKSIZ + inline_ext;
	usedmax = 0;
	bb = NULL;

	list_for_each_entry(cur, &blkh.list, list) {
		unsigned int used_before, used;

		used_before = cur->buffers.off % EROFS_BLKSIZ;

		/* skip if buffer block is just full */
		if (!used_before)
			continue;

		/* skip if the entry which has different type */
		if (cur->type != type)
			continue;

		ret = __erofs_battach(cur, NULL, size, alignsize,
				      required_ext + inline_ext, true);
		if (ret < 0)
			continue;

		used = (ret + required_ext) % EROFS_BLKSIZ + inline_ext;

		/* should contain inline data in current block */
		if (used > EROFS_BLKSIZ)
			continue;

		/*
		 * remaining should be smaller than before or
		 * larger than allocating a new buffer block
		 */
		if (used < used_before && used < used0)
			continue;

		if (usedmax < used) {
			bb = cur;
			usedmax = used;
		}
	}

	if (bb) {
		bh = malloc(sizeof(struct erofs_buffer_head));
		if (!bh)
			return ERR_PTR(-ENOMEM);
		goto found;
	}

	/* allocate a new buffer block */
	if (used0 > EROFS_BLKSIZ)
		return ERR_PTR(-ENOSPC);

	bb = malloc(sizeof(struct erofs_buffer_block));
	if (!bb)
		return ERR_PTR(-ENOMEM);

	bb->type = type;
	bb->blkaddr = NULL_ADDR;
	bb->buffers.off = 0;
	init_list_head(&bb->buffers.list);
	list_add_tail(&bb->list, &blkh.list);

	bh = malloc(sizeof(struct erofs_buffer_head));
	if (!bh) {
		free(bb);
		return ERR_PTR(-ENOMEM);
	}
found:
	ret = __erofs_battach(bb, bh, size, alignsize,
			      required_ext + inline_ext, false);
	if (ret < 0)
		return ERR_PTR(ret);
	return bh;
}

struct erofs_buffer_head *erofs_battach(struct erofs_buffer_head *bh,
					int type, unsigned int size)
{
	struct erofs_buffer_block *const bb = bh->block;
	struct erofs_buffer_head *nbh;
	unsigned int alignsize;
	int ret = get_alignsize(type, &type);

	if (ret < 0)
		return ERR_PTR(ret);
	alignsize = ret;

	/* should be the tail bh in the corresponding buffer block */
	if (bh->list.next != &bb->buffers.list)
		return ERR_PTR(-EINVAL);

	nbh = malloc(sizeof(*nbh));
	if (!nbh)
		return ERR_PTR(-ENOMEM);

	ret = __erofs_battach(bb, nbh, size, alignsize, 0, false);
	if (ret < 0) {
		free(nbh);
		return ERR_PTR(ret);
	}
	return nbh;

}

static erofs_blk_t __erofs_mapbh(struct erofs_buffer_block *bb)
{
	erofs_blk_t blkaddr;

	if (bb->blkaddr == NULL_ADDR)
		bb->blkaddr = tail_blkaddr;

	blkaddr = bb->blkaddr + BLK_ROUND_UP(bb->buffers.off);
	if (blkaddr > tail_blkaddr)
		tail_blkaddr = blkaddr;

	return blkaddr;
}

erofs_blk_t erofs_mapbh(struct erofs_buffer_block *bb, bool end)
{
	struct erofs_buffer_block *t, *nt;

	if (!bb || bb->blkaddr == NULL_ADDR) {
		list_for_each_entry_safe(t, nt, &blkh.list, list) {
			if (!end && (t == bb || nt == &blkh))
				break;
			(void)__erofs_mapbh(t);
			if (end && t == bb)
				break;
		}
	}
	return tail_blkaddr;
}

bool erofs_bflush(struct erofs_buffer_block *bb)
{
	struct erofs_buffer_block *p, *n;
	erofs_blk_t blkaddr;

	list_for_each_entry_safe(p, n, &blkh.list, list) {
		struct erofs_buffer_head *bh, *nbh;
		unsigned int padding;
		bool skip = false;

		if (p == bb)
			break;

		/* check if the buffer block can flush */
		list_for_each_entry(bh, &p->buffers.list, list)
			if (bh->op->preflush && !bh->op->preflush(bh))
				return false;

		blkaddr = __erofs_mapbh(p);

		list_for_each_entry_safe(bh, nbh, &p->buffers.list, list) {
			/* flush and remove bh */
			if (!bh->op->flush(bh))
				skip = true;
		}

		if (skip)
			continue;

		padding = EROFS_BLKSIZ - p->buffers.off % EROFS_BLKSIZ;
		if (padding != EROFS_BLKSIZ)
			dev_fillzero(blknr_to_addr(blkaddr) - padding,
				     padding, true);

		DBG_BUGON(!list_empty(&p->buffers.list));

		erofs_dbg("block %u to %u flushed", p->blkaddr, blkaddr - 1);

		list_del(&p->list);
		free(p);
	}
	return true;
}

void erofs_bdrop(struct erofs_buffer_head *bh, bool tryrevoke)
{
	struct erofs_buffer_block *const bb = bh->block;
	const erofs_blk_t blkaddr = bh->block->blkaddr;
	bool rollback = false;

	/* tail_blkaddr could be rolled back after revoking all bhs */
	if (tryrevoke && blkaddr != NULL_ADDR &&
	    tail_blkaddr == blkaddr + BLK_ROUND_UP(bb->buffers.off))
		rollback = true;

	bh->op = &erofs_drop_directly_bhops;
	erofs_bh_flush_generic_end(bh);

	if (!list_empty(&bb->buffers.list))
		return;

	list_del(&bb->list);
	free(bb);

	if (rollback)
		tail_blkaddr = blkaddr;
}

