#include "fractol.h"

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_fractal(t_fractal *f, char *name)
{
	f->name = name;
	f->zoom = 1.0;
	f->offset_x = 0;
	f->offset_y = 0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
}

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (0x00FF00 * iter / MAX_ITER);
}
