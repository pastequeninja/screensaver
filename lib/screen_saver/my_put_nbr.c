/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Mai Ly Lehoux
*/

void my_putchar(char);

void print_int_minim(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        print_int_minim();
        return (0);
    }
    else if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    else
        my_putchar(nb + '0');
    return (0);
}
