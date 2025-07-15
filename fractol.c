#include "fractol.h"

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= f->width || y < 0 || y >= f->height)
		return ;
	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000);
	return ((iterations * 9) % 255 << 16)
		| ((iterations * 2) % 255 << 8)
		| ((iterations * 5) % 255);
}

void	draw_mandelbrot(t_fractal *f)
{
	int		x, y, it;
	double	cr, ci, zr, zi, tmp;

	y = -1;
	while (++y < f->height)
	{
		x = -1;
		while (++x < f->width)
		{
			cr = (x - f->width / 2.0) * 4.0 / f->width / f->zoom + f->move_x;
			ci = (y - f->height / 2.0) * 4.0 / f->height / f->zoom + f->move_y;
			zr = 0;
			zi = 0;
			it = 0;
			while (zr * zr + zi * zi < 4 && it < f->max_iter)
			{
				tmp = zr * zr - zi * zi + cr;
				zi = 2 * zr * zi + ci;
				zr = tmp;
				it++;
			}
			put_pixel(f, x, y, get_color(it, f->max_iter));
		}
	}
}

void	draw_julia(t_fractal *f)
{
	int		x, y, it;
	double	zr, zi, tmp;

	y = -1;
	while (++y < f->height)
	{
		x = -1;
		while (++x < f->width)
		{
			zr = (x - f->width / 2.0) * 4.0 / f->width / f->zoom + f->move_x;
			zi = (y - f->height / 2.0) * 4.0 / f->height / f->zoom + f->move_y;
			it = 0;
			while (zr * zr + zi * zi < 4 && it < f->max_iter)
			{
				tmp = zr * zr - zi * zi + f->julia_cr;
				zi = 2 * zr * zi + f->julia_ci;
				zr = tmp;
				it++;
			}
			put_pixel(f, x, y, get_color(it, f->max_iter));
		}
	}
}
