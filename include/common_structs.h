#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#include <ultra64.h>

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f; /* sizeof = 0x0C */

typedef struct {
    char* name;
    u8 unk_0x04;
    u8 unk_0x05;
    u8 texture; // for animated textures?
    u8 unk_0x07; // texture size?
    u8 collision;
    u8 unk_0x09; // changing this has some weird effects on physics
    u8 unk_0x0A;
    u8 unk_0x0B; // effects draw order and rendering
} MapObjectEntry;


#endif

