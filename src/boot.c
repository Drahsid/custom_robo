#include "common.h"
#include "thread.h"

extern void func_8004B8C0(void); // libultra?
extern void func_800293C0(s32, s32); // libultra?
extern void func_8005B5E0(s32); // libultra?
extern void func_80059A70(OSThread*, s32); // libultra?

extern void func_8002714C(s32 arg0);
extern void (*D_80129390)(void);

void idle(s32 arg0);

void boot(void) {
    osInitialize();
    osCreateThread(&sIdleThread, 1, idle, NULL, gIdleStack + (sizeof(gIdleStack) / sizeof(u64)), 10);
    osStartThread(&sIdleThread);
}

void idle(s32 arg0) {
    D_80129390 = NULL;
    func_8004B8C0();
    func_800293C0(2, 1);
    func_8005B5E0(0x5A);
    osCreateThread(&sUnk0Thread, 3, func_8002714C, NULL, gUnk0Stack + (sizeof(gUnk0Stack) / sizeof(u64)), 10);
    osStartThread(&sUnk0Thread);
    func_80059A70(&sIdleThread, 0);

    while (1) {
        if (D_80129390 != NULL) {
            D_80129390();
        }
    }
}

void func_80046560(void) {}

