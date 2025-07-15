#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
	char	*name;
	double	julia_cr;
	double	julia_ci;
}	t_fractal;

void	init_window(t_fractal *f);
void	draw_mandelbrot(t_fractal *f);
void	draw_julia(t_fractal *f);
void	put_pixel(t_fractal *f, int x, int y, int color);
int		handle_key(int keycode, t_fractal *f);
int		handle_mouse(int button, int x, int y, t_fractal *f);
int		close_program(t_fractal *f);
int		get_color(int iterations, int max_iter);

#endif
