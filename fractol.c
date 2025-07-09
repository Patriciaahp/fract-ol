#include "fractol.h"

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 65307) // ESC
		close_window(f);
	else if (keycode == 65361) // ←
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 65363) // →
		f->offset_x += 0.1 / f->zoom;
	else if (keycode == 65362) // ↑
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == 65364) // ↓
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 61 || keycode == 65451) // +
		f->zoom *= 1.1;
	else if (keycode == 45 || keycode == 65453) // -
		f->zoom /= 1.1;

	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(f);
	else if (ft_strncmp(f->name, "julia", 5) == 0)
		draw_julia(f);
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

void	init_window(t_fractal *f)
{
	f->zoom = 1;
	f->offset_x = -0.5;
	f->offset_y = 0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);

	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(f);
	else if (ft_strncmp(f->name, "julia", 5) == 0)
		draw_julia(f);

	mlx_key_hook(f->win, handle_key, f);
	mlx_hook(f->win, 17, 0, close_window, f);
	mlx_loop(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal f;

	if (argc != 2 || 
		(ft_strncmp(argv[1], "mandelbrot", 10) != 0 &&
		ft_strncmp(argv[1], "julia", 5) != 0))
	{
		write(1, "Usage: ./fractol mandelbrot | julia\n", 37);
		return (1);
	}
	f.name = argv[1];
	f.julia_cr = -0.8;
	f.julia_ci = 0.156;
	init_window(&f);
	return (0);
}
