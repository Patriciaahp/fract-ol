#include "fractol.h"

static int	julia(double zr, double zi, double cr, double ci)
{
	int		i = 0;
	double	tmp;

	while (zr * zr + zi * zi <= 4 && i < 100)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

static void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_julia(t_fractal *f)
{
	int		x, y, it;
	double	zr, zi;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zr = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->offset_x;
			zi = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->offset_y;
			it = julia(zr, zi, f->julia_cr, f->julia_ci);
			put_pixel(f, x, y, it * 0x00101010);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
