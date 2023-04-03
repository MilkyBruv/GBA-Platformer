#include <stdint.h>
#include <stdbool.h>
#include "gba_input.h"

typedef uint8_t	u8;		
typedef uint16_t u16;	
typedef uint32_t u32;	
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef volatile uint8_t v_u8;
typedef volatile uint16_t v_u16;
typedef volatile uint32_t v_u32;
typedef volatile int8_t v_s8;
typedef volatile int16_t v_s16;
typedef volatile int32_t v_s32;

#define REG_DISPCNT *((v_u32*)(0x04000000))
#define REG_VCOUNT (*(v_u16*)(0x04000006))
#define VIDEOMODE_3 0x0003
#define BGMODE_2	0x0400

#define SCREENBUFFER ((v_u16*)(0x06000000))
#define SCREEN_W 240
#define SCREEN_H 160

s32 __gba_rand_seed = 42;

s32 abs(s32 _val);

u16 set_colour(u8 _red, u8 _green, u8 _blue);

void plot_pixel( u32 _x, u32 _y, u16 _colour);

void draw_rect(u32 _x, u32 _y, u32 _width, u32 _height, u16 _colour);

void draw_line(u32 _x, u32 _y, u32 _x2, u32 _y2, u16 _colour);

s32 seed_gba_rand(s32 _seed);

s32 gba_rand();

s32 gba_rand_range(s32 _min, s32 _max);

void vsync();