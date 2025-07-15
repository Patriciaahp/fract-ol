#include "fractol.h"

int	handle_no_args(void)
{
	write(1, "Usage:\n", 7);
write(1, "./fractol mandelbrot\n", 22);
	write(1, "./fractol julia [real] [imaginary]\n", 36);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc < 2)
		return (handle_no_args());
	init_fractal(&fractal, argv[1]);
	if (!strcmp(argv[1], "julia"))
	{
		if (argc == 4)
		{
			fractal.julia_k.re = atof(argv[2]);
			fractal.julia_k.im = atof(argv[3]);
		}
		else
		{
			fractal.julia_k.re = -0.4;
			fractal.julia_k.im = 0.6;
		}
	}
	draw_fractal(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, close_window, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
