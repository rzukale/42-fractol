/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:49:09 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:58:44 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_random_color(void)
{
	int		red;
	int		green;
	int		blue;

	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	zoom(int x, int y, t_ins *ins, double zoom_factor)
{
	ins->f.zoom *= zoom_factor;
	ins->f.offset_x = (ins->f.offset_x + (WIDTH * 0.5) - x) * zoom_factor;
	ins->f.offset_y = (ins->f.offset_y + (HEIGHT * 0.5) - y) * zoom_factor;
	if (zoom_factor > 1)
		ins->f.max_iter++;
	draw(ins);
}

void	switch_fractals(t_ins *inst, int key)
{
	t_ins *ins;

	ins = inst;
	if (key == KEY_1)
		ins->fractal_type = 1;
	else if (key == KEY_2)
		ins->fractal_type = 2;
	else if (key == KEY_3)
		ins->fractal_type = 3;
	else if (key == KEY_4)
		ins->fractal_type = 4;
	else if (key == KEY_5)
		ins->fractal_type = 5;
	else if (key == KEY_6)
		ins->fractal_type = 6;
	else if (key == KEY_7)
		ins->fractal_type = 7;
	else if (key == KEY_8)
		ins->fractal_type = 8;
	reset(ins);
}

void	reset(t_ins *inst)
{
	t_ins	*ins;

	ins = inst;
	reinit_fractal(ins);
	draw(ins);
}

void	print_menu(t_ins *ins)
{
	char	*str;

	str = "Press 'H' to bring up help menu";
	mlx_string_put(ins->mlx, ins->win, 10, 20, 0x437613, str);
	str = "Move fractal: Arrow keys";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 20, 0x437613, str);
	str = "Switch between fractals: 1-8";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 40, 0x437613, str);
	str = "Zoom: Mouse wheel & left click;"
		"de-zoom with mouse wheel & right click";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 60, 0x437613, str);
	str = "Increase max iterations: 'Z' ; 'X'";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 80, 0x437613, str);
	str = "Random Color: 'T'; Change color scheme with 'Y'";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 100, 0x437613, str);
	str = "Reset fractal: 'R'";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 120, 0x437613, str);
	str = "Lock/unlock mouse: 'SPACE'";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 140, 0x437613, str);
	str = "Exit with 'ESC'";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 180, 0x437613, str);
	str = "NOTE: Mouse zooming only possible with mouse locked";
	mlx_string_put(ins->mlx, ins->win, 10, 20 + 200, 0x437613, str);
	check_mouselock(ins);
}
