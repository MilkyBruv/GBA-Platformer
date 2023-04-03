#include <stdint.h>
#include <stdbool.h>
#include "gba_input.h"
#include "gba_tools.h"


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

    draw_rect(player->x, player->y, player->width, player->height, player->colour);

}

void clear_player(Player* player)
{

    draw_rect(player->x, player->y, player->width, player->height, set_colour(0, 0, 0));

}


typedef struct Platform
{

    s32 x;
    s32 y;
    s32 width;
    s32 height;
    u16 colour;

} Platform;

void init_platform(Platform* platform, s32 _x, s32 _y, s32 _width, s32 _height, u16 _colour)
{

    platform->x = _x;
    platform->y = _y;
    platform->width = _width;
    platform->height = _height;
    platform->colour = _colour;

}

void draw_platform(Platform* platform)
{

    draw_rect(platform->x, platform->y, platform->width, platform->height, platform->colour);

}

void clear_platform(Platform* platform)
{

    draw_rect(platform->x, platform->y, platform->width, platform->height, set_colour(0, 0, 0));

}


int main()
{
    
	REG_DISPCNT = VIDEOMODE_3 | BGMODE_2;
    draw_rect(0, 0, SCREEN_W, SCREEN_H, set_colour(0, 0, 0));

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