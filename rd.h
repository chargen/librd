/*
 * librd - Rapid Development C library
 *
 * Copyright (c) 2012, Magnus Edenhill
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */



#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <alloca.h>
#include <assert.h>
#include <pthread.h>

#include "rdtypes.h"



#define likely(x)   __builtin_expect((x),1)
#define unlikely(x) __builtin_expect((x),0)

#define RD_UNUSED   __attribute__((unused))

#define RD_ARRAYSIZE(A)           (sizeof((A)) / sizeof(*(A)))
#define RD_SIZEOF(TYPE,MEMBER)    sizeof(((TYPE *)NULL)->MEMBER)
#define RD_OFFSETOF(TYPE,MEMBER)  ((size_t) &(((TYPE *)NULL)->MEMBER))


/**
 * Cap an integer (of any type) to reside within the defined limit.
 */
#define RD_INT_CAP(val,low,hi) \
	((val) < (low) ? low : ((val) > (hi) ? (hi) : (val)))


#define rd_atomic_add(PTR,VAL)  __sync_add_and_fetch(PTR,VAL)
#define rd_atomic_sub(PTR,VAL)  __sync_sub_and_fetch(PTR,VAL)

#define rd_atomic_add_prev(PTR,VAL)  __sync_fetch_and_add(PTR,VAL)
#define rd_atomic_sub_prev(PTR,VAL)  __sync_fetch_and_sub(PTR,VAL)


void rd_init (void);