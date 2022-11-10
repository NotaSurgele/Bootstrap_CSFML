#include <stdio.h>
#include <SFML/Graphics.h>
#include "struct.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Space invaders", sfClose, NULL);
    sfEvent event = {0};
    player_t *player = create_player("assets/ship_1.png", V2F(400, 200));
    cursor_t *cursor = create_cursor("assets/laser.png");
    sfClock *clock = sfClock_create();
    sfTime time = {0};

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_restart(clock);
        float deltaTime = sfTime_asSeconds(time);
        while (sfRenderWindow_pollEvent(window, &event)) {
            cursor->mouse_pos = sfMouse_getPositionRenderWindow(window);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (sfKeyboard_isKeyPressed(sfKeyD))
                sfSprite_move(player->sprite, V2F(50 * deltaTime, 0));
            if (sfKeyboard_isKeyPressed(sfKeyQ))
                sfSprite_move(player->sprite, V2F(-50 * deltaTime, 0));
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                if (sfFloatRect_contains(&player->collision_box, 
                    cursor->mouse_pos.x, cursor->mouse_pos.y)) {
                    player->texture = sfTexture_createFromFile("assets/ship_2.png", NULL);
                    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
                }
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_player(player, window);  
        draw_cursor(cursor, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}