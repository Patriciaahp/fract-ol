#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_fractal;

void	init_window(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	draw_mandelbrot(t_fractal *f);
int		close_window(t_fractal *f);
int		handle_key(int keycode, t_fractal *f);

#endif
