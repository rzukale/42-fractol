/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:40:22 by rzukale           #+#    #+#             */
/*   Updated: 2020/08/10 19:29:15 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	t_ins	**ins;
	int		i;

	if (argc < 2 || argc > 3)
		usage();
	if (validate_parameters(argv, argc) < 0)
		display_error(-2);
	if (!(ins = (t_ins**)malloc(sizeof(t_ins*))))
		display_error(-1);
	if ((mlx = mlx_init()) == NULL)
		display_error(-3);
	i = 1;
	while (i < argc)
	{
		ins[i - 1] = init_instance(argv[i], &mlx);
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
