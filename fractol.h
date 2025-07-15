#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

// Key codes
# define ESC_KEY       65307

// Mouse buttons
# define ZOOM_IN       4  // Scroll up
# define ZOOM_OUT      5  // Scroll down


typedef struct s_complex {
	double re;
	double im;
} t_complex;

typedef struct s_fractal {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*name;
	double	zoom;
	double	offset_x;
	double	offset_y;
	t_complex julia_k;
	int		julia_mouse_lock;
} t_fractal;

void		init_fractal(t_fractal *f, char *name);
void		draw_fractal(t_fractal *f);
void		draw_mandelbrot(t_fractal *f);
void		draw_julia(t_fractal *f);
int			key_hook(int keycode, t_fractal *f);
int			mouse_hook(int button, int x, int y, t_fractal *f);
int			close_window(t_fractal *f);
void		put_pixel(t_fractal *f, int x, int y, int color);
t_complex	screen_to_complex(int x, int y, t_fractal *f);
int get_color(int iteration);

#endif