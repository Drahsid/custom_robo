#ifndef THREAD_H
#define THREAD_H

#include <PR/ultratypes.h>

#define STACK_SIZE (0x2000)

extern OSThread sIdleThread;
extern OSThread sUnk0Thread;
extern u64 gUnk0Stack[STACK_SIZE / sizeof(u64)];
extern u64 gIdleStack[STACK_SIZE / sizeof(u64)]; // stack idle

#endif

