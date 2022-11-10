#include "struct.h"

void draw_player(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
