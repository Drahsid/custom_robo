#ifndef ROBO_CHARACTER_H
#define ROBO_CHARACTER_H

#include "common.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA;

typedef struct {
    /* 0x00000 */ u32 unk_0x00;
    /* 0x00004 */ u32 unk_0x04;
    /* 0x00008 */ u16 fighterIndex;
    /* 0x0000A */ u16 timer;
    /* 0x0000C */ f32 cDashFXTimer;
    /* 0x00010 */ u32 shootFXTimer0;
    /* 0x00014 */ u32 shootFXTimer1;
    /* 0x00018 */ u32 unk_0x18; // effects the shoot fx
    /* 0x0001C */ u32 unk_0x1C; // effects the shoot fx
    /* 0x00020 */ u32 unk_0x20;
    /* 0x00024 */ u32 unk_0x24;
    /* 0x00028 */ u8 unk_0x28;
    /* 0x00029 */ u8 wasHit;
    /* 0x0002A */ s16 damageReceived;
    /* 0x0002C */ u8 knockbackDowns;
    /* 0x0002D */ u8 unk_0x2D;
    /* 0x0002E */ u16 knockbackPower;
    /* 0x00030 */ u16 unk_0x13C0;
    /* 0x00032 */ u16 flinchLag;
    /* 0x00034 */ u16 unk_0x34;
    /* 0x00036 */ u16 unk_0x36;
    /* 0x00038 */ u32 unk_0x38;
    /* 0x0003C */ u32 unk_0x3C;
    /* 0x00040 */ u32 unk_0x40;
    /* 0x00044 */ u32 unk_0x44;
    /* 0x00048 */ u32 unk_0x48;
    /* 0x0004C */ u32 unk_0x4C;
    /* 0x00050 */ u32 unk_0x50;
    /* 0x00054 */ u32 unk_0x54;
    /* 0x00058 */ u32 unk_0x58;
    /* 0x0005C */ u32 unk_0x5C;
    /* 0x00060 */ u32 unk_0x60;
    /* 0x00064 */ u32 unk_0x64;
    /* 0x00068 */ u32 unk_0x68;
    /* 0x0006C */ u32 unk_0x6C;
    /* 0x00070 */ RGBA lightColor0;
    /* 0x00074 */ RGBA lightColor1;
    /* 0x00078 */ RGBA unk_0x78;
    /* 0x0007C */ RGBA unk_0x7C;
    /* 0x00080 */ RGBA unk_0x80; // light dir?
    /* 0x00084 */ RGBA unk_0x84;
    /* 0x00088 */ RGBA unk_0x88; // material color?
    /* 0x0008C */ RGBA unk_0x8C; // material color?
    /* 0x00090 */ RGBA unk_0x90; // material color?
    /* 0x00094 */ u32 unk_0x94;
    /* 0x00098 */ u32 unk_0x98;
    /* 0x0009C */ u32 unk_0x9C;
    /* 0x000A0 */
} RoboInfo;

typedef struct {
    /* 0x0000 */ u32 unk_0x00;
    /* 0x0004 */ u32 unk_0x04;
    /* 0x0008 */ char name[0x20];
} RoboBody;

typedef struct {
    /* 0x0000 */ u32 unk_0x00;
    /* 0x0004 */ u32 unk_0x04;
    /* 0x0008 */ char name[0x20];
    /* 0x0028 */ u8 unk_0x28[0xDC];
    /* 0x0104 */ u8 unk_0x104;
    /* 0x0105 */ u8 unk_0x105;
    /* 0x0106 */ u8 unk_0x106;
    /* 0x0107 */ u8 unk_0x107;
    /* 0x0108 */ u16 unk_0x108;
    /* 0x010A */ u16 timer;
    /* 0x010C */ void* unk_0x1390_pointer;
    /* 0x0110 */ RoboBody* body;
    /* 0x0114 */ u32 unk_0x114;
    /* 0x0118 */ u32 unk_0x118;
    /* 0x011C */ u32 unk_0x11C;
    /* 0x0148 */ // referenced
    /* 0x01D0 */ // referenced
    /* 0xD858 */ // referenced
} RoboGun;

typedef struct {
    /* 0x0000 */ u32 unk_0x00;
    /* 0x0004 */ u32 unk_0x04;
    /* 0x0008 */ char name[0x20];
} RoboBomb;

typedef struct {
    /* 0x00000 */ u8 playerIndex;
    /* 0x00001 */ u8 move_flags0; // running state?
    /* 0x00002 */ u8 move_flags1; // 0 = walk, 1 = run, 2 = falling
    /* 0x00003 */ u8 unk_0x03;
    /* 0x00004 */ u8 state; // 0 and 1 = launching, 2 and 3 = getting up, 4 = active
    /* 0x00005 */ u8 unk_0x05;
    /* 0x00006 */ u8 unk_0x06;
    /* 0x00007 */ u8 unk_0x07; // timer
    /* 0x00008 */ u8 unk_0x08; // spawns attack id? maybe animation?
    /* 0x00009 */ u8 unk_0x09;
    /* 0x0000A */ u8 unk_0x0A;
    /* 0x0000B */ u8 unk_0x0B;
    /* 0x0000C */ u8 rebirthTimer;
    /* 0x0000D */ u8 unk_0x0D;
    /* 0x0000E */ u8 turnAmount;
    /* 0x0000F */ u8 unk_0x0F;
    /* 0x00010 */ s16 unk_0x10;
    /* 0x00012 */ s16 knockdownTimer;
    /* 0x00014 */ s16 unk_0x14;
    /* 0x00016 */ u8 unk_0x16;
    /* 0x00017 */ u8 unk_0x17;
    /* 0x00018 */ u8 unk_0x18;
    /* 0x00019 */ u8 unk_0x19;
    /* 0x0001A */ s16 unk_0x1A;
    /* 0x0001C */ f32 unk_0x1C;
    /* 0x00020 */ f32 hitPoints; // 1.0f = 1000
    /* 0x00024 */ f32 unk_0x24; // makes a sound when set, crash prone
    /* 0x00028 */ f32 unk_0x28;
    /* 0x0002C */ u32 unk_0x2C;
    /* 0x00030 */ f32 unk_0x30;
    /* 0x00034 */ f32 unk_0x34;
    /* 0x00038 */ f32 unk_0x38;
    /* 0x0003C */ Vec3f pos;
    /* 0x00048 */ Vec3f vel;
    /* 0x00054 */ f32 unk_0x54;
    /* 0x00058 */ f32 unk_0x58; // affects momentum
    /* 0x0005C */ f32 unk_0x5C;
    /* 0x00060 */ f32 unk_0x60;
    /* 0x00064 */ f32 unk_0x64;
    /* 0x00068 */ f32 unk_0x68;
    /* 0x0006C */ f32 unk_0x6C;
    /* 0x00070 */ f32 unk_0x70;
    /* 0x00074 */ f32 unk_0x74;
    /* 0x00078 */ Vec3f focus; // camera focus
    /* 0x00084 */ Vec3f unk_0x84;
    /* 0x00090 */ Vec3f unk_0x90;
    /* 0x0009C */ void* unk_0x9C;
    /* 0x000A0 */ void* unk_0xA0;
    /* 0x000A4 */ Vec3f* targetPos; // Might be some sort of transform struct, inside this struct
    /* 0x000A8 */ struct RoboCharacter* targetRobo;
    /* 0x000AC */ void* unk_0xAC;
    /* 0x000B0 */ u16 speed;
    /* 0x000B2 */ s16 acce0;
    /* 0x000B4 */ s16 acce1;
    /* 0x000B6 */ s16 jumpSpeed;
    /* 0x000B8 */ s16 jumpAccel0;
    /* 0x000BA */ s16 jumpAccel1;
    /* 0x000BC */ s16 landingLag;
    /* 0x000BE */ s16 jumpGravity;
    /* 0x000C0 */ s16 airDashWindup;
    /* 0x000C2 */ s16 unk_0xC2;
    /* 0x000C4 */ s16 unk_0xC4;
    /* 0x000C6 */ s16 airDashEndLag;
    /* 0x000C8 */ s16 airSpeed;
    /* 0x000CA */ s16 unk_0xCA;
    /* 0x000CC */ u8 unk_0xCC[0x12C4];
    /* 0x01390 */ RoboInfo unk_0x1390;
    /* 0x01430 */ void* unk_0x1430;
    /* 0x01434 */ u8 unk_0x1434[0x34C4];
    /* 0x048F8 */ Gfx* headDisplayList;
    /* 0x048FC */ u8 unk_0x48FC[0x1230C];
    /* 0x16C08 */ u32 skeletonIndex;
    /* 0x1B1C8 */ // RoboBody
    /* 0x1B338 */ // RoboGun (func_801E6F80_D4DA0)
    /* 0x2CBA0 */ // string for bomb (func_801E9930_D7750)
    /* 0x381F0 */ // string for pod (func_801EC310_DA130)
    /* 0x41268 */ // string for legs (func_801EEF90_DCDB0)
} RoboCharacter;

extern RoboCharacter D_80240C40_12EA60; // player 0
extern RoboCharacter D_8028AA78_178898; // player 1

extern RoboCharacter* BattleArena_Setup_Fighter(RoboCharacter* thisx, RoboCharacter* target, s8 fighter_index, s32 arg3);
extern void func_801E6F80_D4DA0(RoboGun* gun, void* unk_0x1390, RoboBody* body);
extern void func_801E9930_D7750(RoboBomb* bomb, RoboBody* this_body, RoboBody* target_body);

extern void* func_8017AA7C_A038C(RoboInfo* arg0, s16 fighter_index);

#endif

