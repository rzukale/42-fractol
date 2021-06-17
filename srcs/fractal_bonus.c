/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:44:42 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 17:15:03 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_tricorn(t_fractol *fr, int *i, t_coords c)
{
	double		tmp;
	t_fractol	f;

	f = *fr;
	f.min_x = ((f.offset_x + (WIDTH * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.min_y = ((f.offset_y + (HEIGHT * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.c.real = c.x / f.zoom + f.min_x;
	f.c.imag = c.y / f.zoom + f.min_y;
	f.z.real = 0;
	f.z.imag = 0;
	while (((f.z.real * f.z.real + f.z.imag * f.z.imag) < 4) &&
		(*i) < f.max_iter)
	{
		tmp = f.z.real * f.z.real - f.z.imag * f.z.imag + f.c.real;
		f.z.imag = -2 * f.z.real * f.z.imag + f.c.imag;
		f.z.real = tmp;
		(*i)++;
	}
}

void		draw_bird_of_prey(t_fractol *fr, int *i, t_coords c)
{
	double		tmp_real;
	double		tmp_imag;
	t_fractol	f;

	f = *fr;
	f.min_x = ((f.offset_x + (WIDTH * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.min_y = ((f.offset_y + (HEIGHT * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.c.real = c.x / f.zoom + f.min_x;
	f.c.imag = c.y / f.zoom + f.min_y;
	f.z.real = 0;
	f.z.imag = 0;
	while (((f.z.real * f.z.real + f.z.imag * f.z.imag) < 4) &&
		(*i) < f.max_iter)
	{
		f.z.real = fabs(f.z.real);
		f.z.imag = fabs(f.z.imag);
		tmp_imag = (((f.z.real * f.z.real) * 3) - (f.z.imag * f.z.imag)) *
			f.z.imag + f.c.imag;
		tmp_real = ((f.z.real * f.z.real) - ((f.z.imag * f.z.imag) * 3)) *
			f.z.real + f.c.real;
		f.z.real = tmp_real;
		f.z.imag = tmp_imag;
		(*i)++;
	}
}

void		draw_cubic_mandelbrot(t_fractol *fr, int *i, t_coords c)
{
	double		tmp;
	t_fractol	f;

	f = *fr;
	f.min_x = ((f.offset_x + (WIDTH * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.min_y = ((f.offset_y + (HEIGHT * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.c.real = c.x / f.zoom + f.min_x;
	f.c.imag = c.y / f.zoom + f.min_y;
	f.z.real = 0;
	f.z.imag = 0;
	while ((f.z.real * f.z.real + f.z.imag * f.z.imag) < 4 &&
		(*i) < f.max_iter)
	{
		tmp = (f.z.real * f.z.real * f.z.real) - 3 * f.z.real * (f.z.imag *
			f.z.imag) + f.c.real;
		f.z.imag = 3 * (f.z.real * f.z.real) * f.z.imag - (f.z.imag * f.z.imag *
			f.z.imag) + f.c.imag;
		f.z.real = tmp;
		(*i)++;
	}
}

void		draw_quintic_mandelbrot(t_fractol *fr, int *i, t_coords c)
{
	double		tmp;
	t_fractol	f;

	f = *fr;
	f.min_x = ((f.offset_x + (WIDTH * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.min_y = ((f.offset_y + (HEIGHT * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.c.real = c.x / f.zoom + f.min_x;
	f.c.imag = c.y / f.zoom + f.min_y;
	f.z.real = 0;
	f.z.imag = 0;
	while ((f.z.real * f.z.real + f.z.imag * f.z.imag) < 4 &&
		(*i) < f.max_iter)
	{
		tmp = (f.z.real * f.z.real * f.z.real * f.z.real * f.z.real) - 10
			* (f.z.real * f.z.real * f.z.real) * (f.z.imag * f.z.imag) + 5
			* f.z.real * (f.z.imag * f.z.imag * f.z.imag * f.z.imag) + f.c.real;
		f.z.imag = 5 * (f.z.real * f.z.real * f.z.real * f.z.real) * f.z.imag
			- 10 * (f.z.real * f.z.real) * (f.z.imag * f.z.imag * f.z.imag)
			+ (f.z.imag * f.z.imag * f.z.imag * f.z.imag * f.z.imag) + f.c.imag;
		f.z.real = tmp;
		(*i)++;
	}
}

void		draw_celtic(t_fractol *fr, int *i, t_coords c)
{
	double		tmp;
	t_fractol	f;

	f = *fr;
	f.min_x = ((f.offset_x + (WIDTH * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.min_y = ((f.offset_y + (HEIGHT * 0.5)) / (f.zoom * 0.5)) * -0.5;
	f.c.real = c.x / f.zoom + f.min_x;
	f.c.imag = c.y / f.zoom + f.min_y;
	f.z.real = 0;
	f.z.imag = 0;
	while ((f.z.real * f.z.real + f.z.imag * f.z.imag) < 4 &&
		(*i) < f.max_iter)
	{
		tmp = fabs(f.z.real * f.z.real - f.z.imag * f.z.imag) - f.c.real;
		f.z.imag = 2 * f.z.real * f.z.imag - f.c.imag;
		f.z.real = tmp;
		(*i)++;
	}
}
