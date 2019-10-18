/*
** EPITECH PROJECT, 2018
** proto
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

struct display {
    sfTexture* texture;
    sfSprite* sprite;
    sfRenderWindow* window;
};

struct coords_line {
    int y0;
    int y1;
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;
};

typedef struct coords_line coords_line_t;
typedef struct display display_t;
typedef struct framebuffer framebuffer_t;
framebuffer_t *random_lines(framebuffer_t*);
coords_line_t *give_coords_line(int, int);
int redirect_scenes(int, framebuffer_t *, sfColor);
sfColor color_is_random(void);
void window_is_animated_or_closed(display_t *, sfEvent);
void infinity_scenes(int, framebuffer_t*, display_t*);
int scene2_pink_is_display(framebuffer_t *, int, int);
int scene3_is_display(framebuffer_t *, int, int);
void one_argument(void);
int rand(void);
double sin(double);
void scene_changing(int, display_t *);
int abs(int);
void scene_is_display(int);
int my_put_plasma(framebuffer_t *, unsigned int, unsigned int);
int scene2_is_display(framebuffer_t *, int, int);
int scene1_is_display(framebuffer_t *, sfColor color, int, int);
framebuffer_t *framebuffer_create(unsigned int, unsigned int);
int my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor color);
int safe_random_x(void);
int safe_random_y(void);
int animation_id(char *);
void h_flag(void);
void d_flag(void);
int error_gestion(int, char **);
int print_usage(char *);
void my_putstr(char const *);
void my_putchar(char);
int my_strlen(char *);
int my_put_nbr(int);

#endif
