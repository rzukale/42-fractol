/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:32:12 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 15:20:26 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_fractal(t_ins *inst, t_coords c)
{
	int		i;
	t_ins	*ins;

	ins = inst;
	i = 0;
	if (ins->fractal_type == 1)
		draw_julia(&ins->f, &i, c);
	else if (ins->fractal_type == 2)
		draw_mandelbrot(&ins->f, &i, c);
	else if (ins->fractal_type == 3)
		draw_burningship(&ins->f, &i, c);
	else if (ins->fractal_type == 4)
		draw_tricorn(&ins->f, &i, c);
	else if (ins->fractal_type == 5)
		draw_bird_of_prey(&ins->f, &i, c);
	else if (ins->fractal_type == 6)
		draw_cubic_mandelbrot(&ins->f, &i, c);
	else if (ins->fractal_type == 7)
		draw_quintic_mandelbrot(&ins->f, &i, c);
	else if (ins->fractal_type == 8)
		draw_celtic(&ins->f, &i, c);
	if (i == ins->f.max_iter)
		put_pixel_to_image(ins, c, ins->f.no_escape);
	else
		put_pixel_to_image(ins, c, ins->f.color * i);
}

t_coords	get_coords(int x, int y)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

void		*draw_thread(void *ins)
{
	t_ins	*instance;
	int		x;
	int		y;

	instance = (t_ins*)ins;
	y = (int)(HEIGHT / THREADS) * instance->thread_id;
	while (y < (int)((HEIGHT / THREADS) * (instance->thread_id + 1)))
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_fractal(instance, get_coords(x, y));
			x++;
		}
		y++;
	}
	return (NULL);
}

void		clear_image(t_ins *ins)
{
	ft_bzero(ins->img->buffer, WIDTH * HEIGHT * ins->img->bits_per_pixel / 8);
}

void		draw(t_ins *ins)
{
	pthread_t	threads[THREADS];
	t_ins		instance[THREADS];
	int			i;

	i = 0;
	clear_image(ins);
	while (i < THREADS)
	{
		instance[i] = *ins;
		instance[i].thread_id = i;
		pthread_create(&threads[i], NULL, draw_thread, &instance[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img->image, 0, 0);
	if (ins->help)
		print_menu(ins);
}
