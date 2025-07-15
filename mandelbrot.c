#include "fractol.h"

void draw_mandelbrot(t_fractal *f)
{
	int x, y, i;
	t_complex c, z;
	double temp;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
			c.im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
			z.re = 0;
			z.im = 0;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				temp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = temp;
				i++;
			}
			put_pixel(f, x, y, get_color(i));
			x++;
		}
		y++;
	}
}
