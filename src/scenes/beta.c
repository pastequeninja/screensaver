/*
** EPITECH PROJECT, 2018
** second scene
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int my_put_plasma(framebuffer_t *buffer, unsigned int x, unsigned int y)
{
    int courbs = 128.0 + (128.0 * sin(x / 16.0)) + \
    128.0 + (128.0 * sin(y / 16.0)) / 2;

    if (x > 799 || y > 599 || x < 1 || y < 1)
        return (EXIT_ERROR);
    buffer->pixels[4*(y*buffer->width+x)] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+1] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+2] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+3] = courbs;
    return (EXIT_DRAW);
}

int scene2_is_display(framebuffer_t *buffer, int x0, int x1)
{
    coords_line_t* coords = give_coords_line(x0, x1);

    while (1) {
        my_put_plasma(buffer, x0, coords->y0);
        if (x0 == x1 && coords->y0 == coords->y1)
            return (EXIT_DRAW);
        coords->e2 = coords->err;
        if (coords->e2 > (coords->dx) * -1) {
            coords->err -= coords->dy;
            x0 += coords->sx;
        }
        if (coords->e2 < coords->dy) {
            coords->err += coords->dx;
            coords->y0 += coords->sy;
        }
    }
}

int scene2_pink_is_display(framebuffer_t *buffer, int x0, int x1)
{
    sfColor color = {255, 192, 203, 50};
    coords_line_t* coords = give_coords_line(x0, x1);

    while (1) {
        my_put_plasma(buffer, x0, coords->y0);
        if (x0 == x1 && coords->y0 == coords->y1)
            return (EXIT_DRAW);
        coords->e2 = coords->err;
        if (coords->e2 > (coords->dx) * -1) {
            coords->err -= coords->dy;
            x0 += coords->sx;
            my_put_pixel(buffer, x0, coords->y0, color);
        }
        if (coords->e2 < coords->dy) {
            coords->err += coords->dx;
            coords->y0 += coords->sy;
        }
    }
}
