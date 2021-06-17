/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:36:05 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:55:51 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_input(int button, int x, int y, t_ins *ins)
{
	t_ins	*inst;

	inst = ins;
	if (inst->f.is_locked == 1 && x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		if (button == MOUSE_WHEEL_UP || button == MOUSE_LEFT_CLICK)
			zoom(x, y, inst, 1.25);
		if (button == MOUSE_WHEEL_DOWN || button == MOUSE_RIGHT_CLICK)
			zoom(x, y, inst, 1 / 1.25);
	}
	return (1);
}

int		mouse_move(int x, int y, t_ins *ins)
{
	t_ins	*inst;

	inst = ins;
	if (inst->f.is_locked == 0 && x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		inst->f.min_x = ((inst->f.offset_x + (WIDTH * 0.5))
						/ (inst->f.zoom * 0.5)) * -0.5;
		inst->f.min_y = ((inst->f.offset_y + (HEIGHT * 0.5))
						/ (inst->f.zoom * 0.5)) * -0.5;
		inst->f.julia.real = x / inst->f.zoom + inst->f.min_x;
		inst->f.julia.imag = y / inst->f.zoom + inst->f.min_y;
		draw(inst);
	}
	return (1);
}

void	manipulate_image(int key, t_ins *ins)
{
	t_ins *inst;

	inst = ins;
	if (key == KEY_ARROW_UP)
		inst->f.offset_y -= 40;
	else if (key == KEY_ARROW_DOWN)
		inst->f.offset_y += 40;
	else if (key == KEY_ARROW_LEFT)
		inst->f.offset_x -= 40;
	else if (key == KEY_ARROW_RIGHT)
		inst->f.offset_x += 40;
	else if (key == KEY_Z)
		inst->f.max_iter++;
	else if (key == KEY_X && inst->f.max_iter > 0)
		inst->f.max_iter--;
	else if (key == KEY_Y)
		inst->f.no_escape = (inst->f.no_escape) ? 0x000000 : 0xFFFFFF;
	draw(inst);
}

int		keyboard_input(int key, t_ins *ins)
{
	t_ins	*inst;

	inst = ins;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_R)
		reset(inst);
	else if (key == KEY_T)
		inst->f.color = choose_random_color();
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 ||
			key == KEY_5 || key == KEY_6 || key == KEY_7 || key == KEY_8)
		switch_fractals(ins, key);
	else if (key == KEY_SPACE)
		inst->f.is_locked = (inst->f.is_locked) ? 0 : 1;
	else if (key == KEY_H)
		inst->help = (inst->help) ? 0 : 1;
	else if (key == KEY_ARROW_UP || key == KEY_ARROW_DOWN ||
		key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT ||
		key == KEY_Z || key == KEY_X || key == KEY_Y)
		manipulate_image(key, inst);
	draw(inst);
	return (1);
}
