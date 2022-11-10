#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>

#define V2F(x, y) \
        (sfVector2f) { x, y }

#define FRECT(x, y, width, height) \
        (sfFloatRect) {x, y, width, height}

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect collision_box;
} player_t;

typedef struct cursor_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i mouse_pos;
} cursor_t;

player_t *create_player(char const *, sfVector2f);
void draw_player(player_t *, sfRenderWindow *);
cursor_t *create_cursor(char const *path);
void draw_cursor(cursor_t *cursor, sfRenderWindow *win);
