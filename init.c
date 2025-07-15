#include "fractol.h"

void	init_window(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->width, f->height, f->name);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	if (strcmp(f->name, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (strcmp(f->name, "julia") == 0)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_key_hook(f->win, handle_key, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_hook(f->win, 17, 0, close_program, f);
	mlx_loop(f->mlx);
}
