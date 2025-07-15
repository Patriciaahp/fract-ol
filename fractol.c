#include "fractol.h"

void draw_fractal(t_fractal *f)
{
	if (!strcmp(f->name, "mandelbrot"))
		draw_mandelbrot(f);
	else if (!strcmp(f->name, "julia"))
		draw_julia(f);
	else
	{
		write(1, "Invalid fractal type\n", 22);
		exit(1);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
