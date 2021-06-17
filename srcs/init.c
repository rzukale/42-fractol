/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:13:55 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/15 16:32:11 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_program(void *ins)
{
	(void)ins;
	exit(0);
}

t_ins		*init_instance(char *name, void **mlx)
{
	t_ins	*ins;

	if (!(ins = (t_ins*)malloc(sizeof(t_ins))))
		display_error(-1);
	ins->mlx = *mlx;
	ins->img = new_image(ins);
	setup_window(ins, name);
	ins->help = 1;
	init_fractal(ins, name);
	mlx_hook(ins->win, 4, 0, mouse_input, ins);
	mlx_hook(ins->win, 2, 0, keyboard_input, ins);
	mlx_hook(ins->win, 17, 0, close_program, ins);
	mlx_hook(ins->win, 6, 1 << 8, mouse_move, ins);
	draw(ins);
	return (ins);
}

void		setup_window(t_ins *ins, char *name)
{
	char	*tmp;

	tmp = ft_strjoin("Fractol - ", name);
	ins->win = mlx_new_window(ins->mlx, WIDTH, HEIGHT, tmp);
	free(tmp);
}

t_img		*new_image(t_ins *ins)
{
	t_img *image;

	if (!(image = (t_img*)malloc(sizeof(t_img))))
		display_error(-1);
	image->image = mlx_new_image(ins->mlx, WIDTH, HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->bits_per_pixel,
					&image->line_bytes, &image->endian);
	return (image);
}

void		put_pixel_to_image(t_ins *ins, t_coords c, int color)
{
	int		pixel;

	if (ins->img->bits_per_pixel != 32)
		color = mlx_get_color_value(ins->mlx, color);
	if (c.x >= 0 && c.y >= 0 && c.x < WIDTH && c.y < HEIGHT)
	{
		pixel = (c.y * ins->img->line_bytes) + (c.x * 4);
		if (ins->img->endian == 1)
		{
			ins->img->buffer[pixel + 0] = (color >> 24);
			ins->img->buffer[pixel + 1] = (color >> 16) & 0xFF;
			ins->img->buffer[pixel + 2] = (color >> 8) & 0xFF;
			ins->img->buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (ins->img->endian == 0)
		{
			ins->img->buffer[pixel + 0] = (color) & 0xFF;
			ins->img->buffer[pixel + 1] = (color >> 8) & 0xFF;
			ins->img->buffer[pixel + 2] = (color >> 16) & 0xFF;
			ins->img->buffer[pixel + 3] = (color >> 24);
		}
	}
}
