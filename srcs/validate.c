/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:31:15 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/17 16:30:49 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_fractal_type(char *argv)
{
	if (ft_strcmp(argv, "julia") == 0)
		return (1);
	else if (ft_strcmp(argv, "mandelbrot") == 0)
		return (2);
	else if (ft_strcmp(argv, "burningship") == 0)
		return (3);
	else if (ft_strcmp(argv, "tricorn") == 0)
		return (4);
	else if (ft_strcmp(argv, "birdofprey") == 0)
		return (5);
	else if (ft_strcmp(argv, "cubic_mandelbrot") == 0)
		return (6);
	else if (ft_strcmp(argv, "quintic_mandelbrot") == 0)
		return (7);
	else if (ft_strcmp(argv, "celtic") == 0)
		return (8);
	return (-1);
}

int			validate_parameter(char *argv)
{
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "mandelbrot") == 0 ||
		ft_strcmp(argv, "burningship") == 0 ||
		ft_strcmp(argv, "tricorn") == 0 || ft_strcmp(argv, "birdofprey") == 0 ||
		ft_strcmp(argv, "cubic_mandelbrot") == 0 ||
		ft_strcmp(argv, "quintic_mandelbrot") == 0 ||
		ft_strcmp(argv, "celtic") == 0)
		return (0);
	return (-1);
}

void		usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal> OR"
		" /fractol <fractal> <fractal> \n", 2);
	ft_putstr_fd("Fractals:\n- \"julia\"\n- \"mandelbrot\"\n"
		"- \"burningship\"\n", 2);
	ft_putstr_fd("- \"tricorn\"\n- \"birdofprey\"\n- \"cubic_mandelbrot\"\n"
		"- \"quintic_mandelbrot\"\n- \"celtic\"\n", 2);
	exit(0);
}

void		display_error(int nbr)
{
	if (nbr == -1)
		ft_putstr_fd("Memory allocation failed!\n", 2);
	else if (nbr == -2)
		ft_putstr_fd("Parameter not valid!\n", 2);
	else if (nbr == -3)
		ft_putstr_fd("MLX failed to initialize!\n", 2);
	usage();
}

int			validate_parameters(char **argv, int argc)
{
	if (argc == 3)
	{
		if ((validate_parameter(argv[1]) == 0) &&
			(validate_parameter(argv[2]) == 0))
			return (1);
		else
			return (-1);
	}
	return (validate_parameter(argv[1]));
}
