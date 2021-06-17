/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_inits2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:41:44 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:44:13 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia(t_ins *ins)
{
	ins->f.max_iter = 400;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.julia.imag = 0.520000;
	ins->f.julia.real = -0.506667;
	ins->f.is_locked = 0;
}

void		init_celtic(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_quintic_mandelbrot(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_fractal(t_ins *ins, char *name)
{
	ins->fractal_type = get_fractal_type(name);
	if (ins->fractal_type == 1)
		init_julia(ins);
	else if (ins->fractal_type == 2)
		init_mandelbrot(ins);
	else if (ins->fractal_type == 3)
		init_burningship(ins);
	else if (ins->fractal_type == 4)
		init_tricorn(ins);
	else if (ins->fractal_type == 5)
		init_bird_of_prey(ins);
	else if (ins->fractal_type == 6)
		init_cubic_mandelbrot(ins);
	else if (ins->fractal_type == 7)
		init_quintic_mandelbrot(ins);
	else if (ins->fractal_type == 8)
		init_celtic(ins);
}

void		reinit_fractal(t_ins *ins)
{
	if (ins->fractal_type == 1)
		init_julia(ins);
	else if (ins->fractal_type == 2)
		init_mandelbrot(ins);
	else if (ins->fractal_type == 3)
		init_burningship(ins);
	else if (ins->fractal_type == 4)
		init_tricorn(ins);
	else if (ins->fractal_type == 5)
		init_bird_of_prey(ins);
	else if (ins->fractal_type == 6)
		init_cubic_mandelbrot(ins);
	else if (ins->fractal_type == 7)
		init_quintic_mandelbrot(ins);
	else if (ins->fractal_type == 8)
		init_celtic(ins);
}
