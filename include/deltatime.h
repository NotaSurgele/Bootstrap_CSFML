#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>

/* Don't touch this one
*
* You will see the power of the deltaTime
*/
typedef struct time_s {
    sfClock *_clock;
    float deltaTime;
} deltatime_t;