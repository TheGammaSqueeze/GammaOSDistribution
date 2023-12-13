/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _X86_ATOMIC_BITSET_H_
#define _X86_ATOMIC_BITSET_H_

#include <stdint.h>
#include <stdbool.h>

struct AtomicBitset {
    uint32_t numBits;
    uint32_t words[];
};

#define ATOMIC_BITSET_SZ(numbits)	(sizeof(struct AtomicBitset) + ((numbits) + 31) / 8)
#define ATOMIC_BITSET_DECL(nam, numbits, extra_keyword)    extra_keyword uint8_t _##nam##_store [ATOMIC_BITSET_SZ(numbits)] __attribute__((aligned(4))); extra_keyword struct AtomicBitset *nam = (struct AtomicBitset*)_##nam##_store


void atomicBitsetInit(struct AtomicBitset *set, uint32_t numBits);
uint32_t atomicBitsetGetNumBits(const struct AtomicBitset *set);
bool atomicBitsetGetBit(const struct AtomicBitset *set, uint32_t num);
void atomicBitsetClearBit(struct AtomicBitset *set, uint32_t num);
int32_t atomicBitsetFindClearAndSet(struct AtomicBitset *set);

#endif


