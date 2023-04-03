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


s32 abs(s32 _val)
{

	s32 mask = _val >> 31;

	return (_val ^ mask) - mask;

}

u16 set_colour(u8 _red, u8 _green, u8 _blue)
{

	return (_red & 0x1F) | (_green & 0x1F) << 5 | (_blue & 0x1f) << 10;

}

void plot_pixel( u32 _x, u32 _y, u16 _colour)
{

	SCREENBUFFER[_y * SCREEN_W + _x] = _colour;

}

void draw_rect(u32 _x, u32 _y, u32 _width, u32 _height, u16 _colour)
{

	for (u32 y = 0; y < _height; ++y)
	{

		for (u32 x = 0; x < _width; ++x)
		{

			SCREENBUFFER[ (_y + y) * SCREEN_W + _x + x ] = _colour;

		}

	}

}

void draw_line(u32 _x, u32 _y, u32 _x2, u32 _y2, u16 _colour)
{

	s32 w = _x2 - _x;
	s32 h = _y2 - _y;

	s32 dx1 = 0, 
        dy1 = 0, 
        dx2 = 0, 
        dy2 = 0;

	if (w < 0) 
    {
        
        dx1 = dx2 = -1; 
        
    } else if (w > 0) 
    {
        
        dx1 = dx2 = 1;

    }

	if (h < 0)
    { 
        
        dy1 = -1;
        
    } else if (h > 0) {
        
        dy1 = 1;

    }
    
	s32 longest = abs(w);
	s32 shortest = abs(h);

	if (shortest > longest)
	{
        
		longest ^= shortest;
        shortest ^= longest;
        longest ^= shortest;

		if (h < 0) 
        {
            
            dy2 = -1;
            
        } else if (h > 0) {
            
            dy2 = 1;
		    dx2 = 0;

        }

	}
    
	s32 numerator = longest >> 1;
    
	for (s32 i = 0; i <= longest; i++)
	{
        
		plotPixel( _x, _y, _colour);
        
		numerator += shortest;

		if (numerator > longest)  
		{
            
			numerator -= longest;
            
			_x += dx1;
			_y += dy1;

		} else 
		{
            
			_x += dx2;
			_y += dy2;

		}

	}

}

s32 seed_gba_rand(s32 _seed)
{

    s32 old_seed = __gba_rand_seed;
    __gba_rand_seed = _seed;

    return old_seed;

}

s32 gba_rand()
{

    __gba_rand_seed = 166425 * __gba_rand_seed + 1013904223;

    return (__gba_rand_seed >> 16) & 0x7FFF;

}

s32 gba_rand_range(s32 _min, s32 _max)
{

    return (gba_rand() * (_max - _min) >> 15) + _min;

}

void vsync()
{

    while(REG_VCOUNT >= SCREEN_H);
    while(REG_VCOUNT < SCREEN_H);

}


typedef struct Player
{

    s32 x;
    s32 y;
    s32 width;
    s32 height;
    u16 colour;

} Player;

void init_player(Player* player, s32 _x, s32 _y, s32 _width, s32 _height, u16 _colour)
{

    player->x = _x;
    player->y = _y;
    player->width = _width;
    player->height = _height;
    player->colour = _colour;

}

void draw_player(Player* player)
{

    draw_rect();

}


int main()
{
    
	REG_DISPCNT = VIDEOMODE_3 | BGMODE_2;
    drawRect(0, 0, SCREEN_W, SCREEN_H, setColour(0, 0, 0));

	while (1) {

        vsync();
        PollKeys();
        
        // clear

		if(keyDown(UP))
		{
            

		
        }
		
        if(keyDown(DOWN))
		{
            

		
        }

		if(keyDown(A))
		{
            

		
        }
		
        if(keyDown(B))
		{
            

		
        }

        // move

        // draw

	}
	
	return 0;
    
}