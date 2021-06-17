/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:40:45 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 18:06:48 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <pthread.h>
# include <math.h>
# include "keys.h"

# define WIDTH	1000
# define HEIGHT 1000
# define THREADS 24

typedef struct	s_img
{
	void		*image;
	int			bits_per_pixel;
	int			line_bytes;
	int			endian;
	char		*buffer;
}				t_img;

typedef	struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef	struct	s_fractol
{
	t_complex	c;
	t_complex	z;
	t_complex	julia;
	double		offset_x;
	double		offset_y;
	int			color;
	int			no_escape;
	double		zoom;
	double		min_x;
	double		min_y;
	int			max_iter;
	int			is_locked;
}				t_fractol;

typedef	struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef	struct	s_ins
{
	void		*mlx;
	t_fractol	f;
	void		*win;
	t_img		*img;
	int			fractal_type;
	int			thread_id;
	int			help;
}				t_ins;

t_coords		get_coords(int x, int y);
t_img			*new_image(t_ins *ins);
t_ins			*init_instance(char *name, void **mlx);
int				choose_random_color(void);
int				close_program(void *ins);
int				get_fractal_type(char *argv);
int				keyboard_input(int key, t_ins *ins);
int				mouse_input(int button, int x, int y, t_ins *ins);
int				mouse_move(int x, int y, t_ins *ins);
int				validate_parameter(char *argv);
int				validate_parameters(char **argv, int argc);
void			clear_image(t_ins *ins);
void			display_error(int nbr);
void			draw(t_ins *ins);
void			draw_bird_of_prey(t_fractol *fr, int *i, t_coords c);
void			draw_burningship(t_fractol *fr, int *i, t_coords c);
void			draw_celtic(t_fractol *fr, int *i, t_coords c);
void			draw_cubic_mandelbrot(t_fractol *fr, int *i, t_coords c);
void			draw_fractal(t_ins *inst, t_coords c);
void			draw_julia(t_fractol *fr, int *i, t_coords c);
void			draw_mandelbrot(t_fractol *fr, int *i, t_coords c);
void			draw_quintic_mandelbrot(t_fractol *fr, int *i, t_coords c);
void			draw_tricorn(t_fractol *fr, int *i, t_coords c);
void			*draw_thread(void *ins);
void			init_bird_of_prey(t_ins *ins);
void			init_burningship(t_ins *ins);
void			init_celtic(t_ins *ins);
void			init_cubic_mandelbrot(t_ins *ins);
void			init_fractal(t_ins *ins, char *name);
void			init_julia(t_ins *ins);
void			init_mandelbrot(t_ins *ins);
void			init_quintic_mandelbrot(t_ins *ins);
void			init_tricorn(t_ins *ins);
void			manipulate_image(int key, t_ins *ins);
void			put_pixel_to_image(t_ins *ins, t_coords c, int color);
void			print_menu(t_ins *ins);
void			reinit_fractal(t_ins *ins);
void			reset(t_ins *inst);
void			setup_window(t_ins *ins, char *name);
void			switch_fractals(t_ins *inst, int key);
void			usage(void);
void			zoom(int x, int y, t_ins *ins, double zoom_factor);
void			check_mouselock(t_ins *ins);
#endif
