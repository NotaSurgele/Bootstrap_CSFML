#include "struct.h"
#include <stdio.h>

void draw_cursor(cursor_t *cursor, sfRenderWindow *win)
{
    sfSprite_setPosition(cursor->sprite, 
        V2F(cursor->mouse_pos.x, cursor->mouse_pos.y));
    sfRenderWindow_drawSprite(win, cursor->sprite, NULL);
}
