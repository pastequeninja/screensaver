/*
** EPITECH PROJECT, 2018
** redirect my scenes
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void scene_changing(int scene_key, display_t* effects)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfRenderWindow_close(effects->window);
        scene_is_display(scene_key - 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfRenderWindow_close(effects->window);
        scene_is_display(scene_key + 1);
    }
}

void infinity_scenes(int scene_key, framebuffer_t* image, display_t* effects)
{
    sfColor color = color_is_random();

    if (scene_key > 4)
        scene_key = 1;
    if (scene_key == 0)
        scene_key = 4;
    scene_changing(scene_key, effects);
    redirect_scenes(scene_key, image, color);
}

int redirect_scenes(int scene_key, framebuffer_t* image, sfColor color)
{
    int x0 = safe_random_x();
    int x1 = safe_random_y();

    if (scene_key == 1) {
        scene1_is_display(image, color, x0, x1);
        return 0;
    }
    if (scene_key == 2) {
        scene2_is_display(image, x0, x1);
        return 0;
    }
    if (scene_key == 3) {
        scene3_is_display(image, x0, x1);
        return 0;
    }
    if (scene_key == 4) {
        scene2_pink_is_display(image, x0, x1);
        return 0;
    }
    return (EXIT_ERROR);
}
