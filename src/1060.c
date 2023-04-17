#include "common.h"

extern void func_8004CF70(void);
extern void func_8004B940(void);
extern void func_80031B6C(void);
extern void func_8004C9C0(void*);
extern void func_8004B850(void*);
extern void func_8004CA00(void*);
extern void func_8004B900(void*);
extern void func_8004B890(void);
extern void func_8005B5E0(s32);
extern void func_8005374C(void*);
extern void func_80033A40(void);
extern s32 func_8004CA70(void);

extern void func_80026A4C(void); // unknown type
extern void func_80025F18(void); // unknown type
extern void func_80026A2C(void); // unknown type
extern void func_80026958(void); // unknown type

extern u8 D_8007B850;
extern u32 D_800D2870; // unknown type

#pragma GLOBAL_ASM("asm/nonmatchings/1060/func_80025C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1060/func_80025F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1060/func_80026958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1060/func_80026A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1060/func_80026A4C.s")

void func_8002714C(void) {
    if (osTvType == OS_TV_TYPE_NTSC) {
        func_8004CF70();
        D_8007B850 = func_8004CA70();
        func_8004B940();
        func_80031B6C();
        func_8004C9C0(func_80026A4C);
        func_8004B850(func_80025F18);
        func_8004CA00(func_80026A2C);
        func_8004B900(func_80026958);
        func_8004B890();
        func_8005B5E0(1);
        func_8005374C(&D_800D2870);
        func_80033A40();
    }
    while (1) {}
}
