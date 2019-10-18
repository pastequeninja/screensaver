/*
** EPITECH PROJECT, 2018
** pattern_alpha
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

sfVideoMode pixels_mode(void)
{
    sfVideoMode pixels = {800, 600, 32};

    return (pixels);
}

display_t *display_window(void)
{
    display_t *display = malloc(sizeof(display_t));
    sfVideoMode mode = pixels_mode();

    display->texture = sfTexture_create(800, 600);
    display->sprite = sfSprite_create();
    display->window = sfRenderWindow_create(mode, "my_screensaver", \
    sfResize | sfClose, NULL);

    return (display);
}

sfColor color_is_random(void)
{
    sfColor rand_color = {rand(), rand(), rand(), rand()};

    return (rand_color);
}

void window_is_animated_or_closed(display_t* effects, sfEvent event)
{
    while (sfRenderWindow_pollEvent(effects->window, &event))
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(effects->window);
         }
}

void scene_is_display(int scene_key)
{
    framebuffer_t* image = framebuffer_create(800, 600);
    display_t* effects = display_window();
    sfEvent event;

    sfTexture_updateFromPixels(effects->texture, image->pixels, \
    image->width, image->height, 0, 0);
    sfSprite_setTexture(effects->sprite, effects->texture, sfTrue);
    sfTexture_updateFromPixels(effects->texture, image->pixels, \
    image->width, image->height, 0, 0);
    while (sfRenderWindow_isOpen(effects->window)) {
        window_is_animated_or_closed(effects, event);
        infinity_scenes(scene_key, image, effects);
        sfTexture_updateFromPixels(effects->texture, \
        image->pixels, image->width, image->height, 0, 0);
        sfRenderWindow_drawSprite(effects->window, \
        effects->sprite, NULL);
        sfRenderWindow_display(effects->window);
    }
    free(effects);
    free(image);
}
