#include "fractol.h"

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 65307) // ESC
		close_program(f);
	else if (keycode == 65361) // Left
		f->move_x -= 0.1 / f->zoom;
	else if (keycode == 65363) // Right
		f->move_x += 0.1 / f->zoom;
	else if (keycode == 65362) // Up
		f->move_y -= 0.1 / f->zoom;
	else if (keycode == 65364) // Down
		f->move_y += 0.1 / f->zoom;
	if (strcmp(f->name, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (strcmp(f->name, "julia") == 0)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	double	scale = (button == 4) ? 1.1 : 0.9;
	double	px = (double)x / f->width * 2.0 - 1.0;
	double	py = (double)y / f->height * 2.0 - 1.0;

	if (button == 4 || button == 5)
	{
		f->zoom *= scale;
		f->move_x += px / f->zoom * (1 - scale);
		f->move_y += py / f->zoom * (1 - scale);
		if (strcmp(f->name, "mandelbrot") == 0)
			draw_mandelbrot(f);
		else if (strcmp(f->name, "julia") == 0)
			draw_julia(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	return (0);
}

int	close_program(t_fractal *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	exit(0);
}
