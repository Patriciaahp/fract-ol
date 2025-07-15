#include "fractol.h"

int key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC_KEY)
		close_window(f);
	return (0);
}

int mouse_hook(int button, int x, int y, t_fractal *f)
{
	double mouse_re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	double mouse_im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	if (button == ZOOM_IN)
	{
		f->zoom *= 1.1;
		f->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
		f->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);
	}
	else if (button == ZOOM_OUT)
	{
		f->zoom /= 1.1;
		f->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
		f->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);
	}
	draw_fractal(f);
	return (0);
}

int close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}
