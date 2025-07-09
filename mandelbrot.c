#include "fractol.h"

static int	mandelbrot(double cr, double ci)
{
	int		i = 0;
	double	zr = 0, zi = 0, tmp;

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
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_fractal *f)
{
	int		x, y, it;
	double	cr, ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->offset_x;
			ci = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->offset_y;
			it = mandelbrot(cr, ci);
			put_pixel(f, x, y, it * 0x00101010);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	init_window(void)
{
	t_fractal f;

	f.zoom = 1;
	f.offset_x = -0.5;
	f.offset_y = 0;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);

	draw_mandelbrot(&f);

	mlx_key_hook(f.win, handle_key, &f);
	mlx_hook(f.win, 17, 0, close_window, &f); // Cierre al click en la X
	mlx_loop(f.mlx);
}
