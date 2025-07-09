#include "fractol.h"

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		close_window(f);
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_strncmp(argv[1], "mandelbrot", 10) != 0)
	{
		write(1, "Usage: ./fractol mandelbrot\n", 29);
		return (1);
	}

	init_window();
	return (0);
}
