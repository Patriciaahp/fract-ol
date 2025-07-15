#include "fractol.h"

void    my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char    *dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void    draw_fractal(t_fractal *f)
{
	if (strcmp(f->name, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (strcmp(f->name, "julia") == 0)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void    draw_mandelbrot(t_fractal *f)
{
	int x, y, i;
	t_complex z, c;
	double tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = screen_to_complex(x, y, f);
			z.re = 0;
			z.im = 0;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				tmp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = tmp;
				i++;
			}
			my_mlx_pixel_put(f, x, y, i * 0x00F00F);
		}
	}
}

void    draw_julia(t_fractal *f)
{
	int x, y, i;
	t_complex z;
	double tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = screen_to_complex(x, y, f);
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				tmp = z.re * z.re - z.im * z.im + f->julia_k.re;
				z.im = 2 * z.re * z.im + f->julia_k.im;
				z.re = tmp;
				i++;
			}
			my_mlx_pixel_put(f, x, y, i * 0x000FFF);
		}
	}
}
#include "fractol.h"

void    my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char    *dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void    draw_fractal(t_fractal *f)
{
	if (strcmp(f->name, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (strcmp(f->name, "julia") == 0)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void    draw_mandelbrot(t_fractal *f)
{
	int x, y, i;
	t_complex z, c;
	double tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = screen_to_complex(x, y, f);
			z.re = 0;
			z.im = 0;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				tmp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = tmp;
				i++;
			}
			my_mlx_pixel_put(f, x, y, i * 0x00F00F);
		}
	}
}

void    draw_julia(t_fractal *f)
{
	int x, y, i;
	t_complex z;
	double tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = screen_to_complex(x, y, f);
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				tmp = z.re * z.re - z.im * z.im + f->julia_k.re;
				z.im = 2 * z.re * z.im + f->julia_k.im;
				z.re = tmp;
				i++;
			}
			my_mlx_pixel_put(f, x, y, i * 0x000FFF);
		}
	}
}
