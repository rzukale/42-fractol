/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:40:48 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:44:37 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_tricorn(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_burningship(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_cubic_mandelbrot(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_mandelbrot(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}

void		init_bird_of_prey(t_ins *ins)
{
	ins->f.max_iter = 50;
	ins->f.zoom = 300;
	ins->f.color = 265;
	ins->f.no_escape = 0x000000;
	ins->f.offset_x = 0;
	ins->f.offset_y = 0;
	ins->f.is_locked = 1;
}
