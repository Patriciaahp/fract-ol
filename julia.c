#include "fractol.h"

void draw_julia(t_fractal *f)
{
	int x, y, i;
	t_complex z;
	double temp;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
			z.im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				temp = z.re * z.re - z.im * z.im + f->julia_k.re;
				z.im = 2 * z.re * z.im + f->julia_k.im;
				z.re = temp;
				i++;
			}
			put_pixel(f, x, y, get_color(i));
			x++;
		}
		y++;
	}
}
