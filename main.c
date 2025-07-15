#include "fractol.h"

static void	usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "./fractol mandelbrot\n", 22);
	write(1, "./fractol julia [real] [imaginary]\n", 35);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2 || (strcmp(argv[1], "mandelbrot") != 0
			&& strcmp(argv[1], "julia") != 0))
		usage();
	f.name = argv[1];
	f.width = 800;
	f.height = 800;
	f.zoom = 1.0;
	f.move_x = 0.0;
	f.move_y = 0.0;
	f.max_iter = 100;
	f.julia_cr = -0.8;
	f.julia_ci = 0.156;
	if (argc == 4 && strcmp(argv[1], "julia") == 0)
	{
		f.julia_cr = atof(argv[2]);
		f.julia_ci = atof(argv[3]);
	}
	init_window(&f);
	return (0);
}
