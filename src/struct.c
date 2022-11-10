#include "struct.h"
#include <stdlib.h>

player_t *create_player(char const *path, sfVector2f position)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setPosition(player->sprite, position);
    player->collision_box = FRECT(position.x, position.y, 32, 32);
    return player;
}

cursor_t *create_cursor(char const *path)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->sprite = sfSprite_create();
    cursor->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    cursor->mouse_pos = (sfVector2i) {0, 0};
    return cursor;
}
