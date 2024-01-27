/*
 * Copyright (c) 2021 by Rockchip Electronics Co., Ltd. All Rights Reserved.
 *
 *
 * @Author: Randall Zhuo
 * @Date: 2021-10-20 14:08:09
 * @LastEditors: Randall
 * @LastEditTime: 2022-05-23 16:06:27
 * @Description: TODO
 */

#pragma once

typedef void*  RKSVEPBUFFERHANDLE;

class RKSVEPImpl;

class RKSVEPBUFFER
{
public:
    int fd;
    int width;
    int height;
    int stride;
    int size;
    int fmt;
    void* virt_addr;
};

class RKSVEPMemManager
{
public:
    static RKSVEPBUFFER createNPUFTMem();
    static void releaseNPUFTMem(RKSVEPBUFFER &buffer);
};

class RKSVEP
{
private:
    RKSVEPImpl *impl;
private:
    /* data */
   int init();
public:
    RKSVEP(int input_width, int input_height, int output_width, int output_height, bool enable_enhancement_only = false);
    RKSVEP(int input_width, int input_height, int output_width, int output_height, RKSVEPBUFFER npuInerBuffer, bool enable_enhancement_only = false);
    RKSVEP(int input_width, int input_height, int input_fmt, int output_width, int output_height, int output_fmt, RKSVEPBUFFER npuInerBuffer, bool enable_enhancement_only = false);
    ~RKSVEP();
    bool verify();
    int run(RKSVEPBUFFERHANDLE inputBufferHandle);
    int postProcess(RKSVEPBUFFERHANDLE outputBufferHandle, float enhancementRate, bool enable_WithAverging = false);

    RKSVEPBUFFERHANDLE createInputBufferHandle(RKSVEPBUFFER &inputBuffer);
    int destoryInputBufferHandle(RKSVEPBUFFERHANDLE handle);

    RKSVEPBUFFERHANDLE createOutputBufferHandle(RKSVEPBUFFER &outBuffer);
    int destoryOutputBufferHandle(RKSVEPBUFFERHANDLE handle);

    // enhancement only
    RKSVEPBUFFERHANDLE createEnhancementBufferHandle(RKSVEPBUFFER &inputBuffer, RKSVEPBUFFER &outBuffer);
    int destoryEnhancementBufferHandle(RKSVEPBUFFERHANDLE handle);
    int run_enhancement(RKSVEPBUFFERHANDLE handle, float enhancementRate = 0.5f);

};
