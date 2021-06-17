/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:22:33 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:57:28 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_mouselock(t_ins *ins)
{
	char *str;

	if (ins->f.is_locked == 1)
	{
		str = "Mouse is locked";
		mlx_string_put(ins->mlx, ins->win, 10, 20 + 220, 0x437613, str);
	}
	else
	{
		str = "Mouse is unlocked";
		mlx_string_put(ins->mlx, ins->win, 10, 20 + 220, 0x437613, str);
	}
}
