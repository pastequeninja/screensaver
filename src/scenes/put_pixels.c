/*
** EPITECH PROJECT, 2018
** put randoms pixels and create frame
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *pointer = malloc(sizeof(framebuffer_t));

    pointer->width = width;
    pointer->height = height;
    pointer->pixels = malloc(width * height * 4);

    return (pointer);
}

int my_put_pixel(framebuffer_t *buffer, unsigned int x, \
unsigned int y, sfColor color)
{
    if (x > 799 || y > 599 || x < 1 || y < 1)
        return (EXIT_ERROR);
    buffer->pixels[4*(y*buffer->width+x)] = color.r;
    buffer->pixels[4*(y*buffer->width+x)+1] = color.g;
    buffer->pixels[4*(y*buffer->width+x)+2] = color.b;
    buffer->pixels[4*(y*buffer->width+x)+3] = color.a;
    return (EXIT_DRAW);
}

coords_line_t *give_coords_line(int x0, int x1)
{
    coords_line_t *point = malloc(sizeof(coords_line_t));

    point->y0 = safe_random_y();
    point->y1 = safe_random_y();
    point->dx = abs(x1 - x0);
    point->sx = x0<x1 ? 1 : -1;
    point->dy = abs(point->y1 - point->y0);
    point->sy = point->y0 < point->y1 ? 1 : -1;
    point->err = (point->dx > point->dy ? point->dx : (point->dy * -1)) / 2;
    point->e2 = 0;
    return (point);
}

int safe_random_x(void)
{
    int z = rand();

    while (z > 800)
        z = rand();
    return (z);
}

int safe_random_y(void)
{
    int z = rand();

    while (z > 600)
        z = rand();
    return (z);
}
