/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:37 by aelkhali          #+#    #+#             */
/*   Updated: 2023/04/14 17:28:11 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	int i;

	if (!data)
		return ;
	i = -1;
	/* print textures paths */
	printf("NO %s", data->no);
	printf("\n-------------------------------\n");
	printf("SO %s", data->so);
	printf("\n-------------------------------\n");
	printf("WE %s", data->we);
	printf("\n-------------------------------\n");
	printf("EA %s", data->ea);
	printf("\n-------------------------------\n");
	
	/*print RGB Colors */
	printf("F |R = %d, G = %d, B = %d|", data->f[0], data->f[1], data->f[2]);
	printf("C |R = %d, G = %d, B = %d|", data->c[0], data->c[1], data->c[2]);

	/*print map data */
	printf("\n-------------------------------\n");
	while (++i < data->map_height)
		printf("%s**\n", data->map[i]);
	printf("\n-------------------------------\n");
}


int	main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	game = calloc(1, sizeof(t_game));
	if (ac == 1 || ac > 2 || ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
		return (ft_error("Invalid arguments\n"), EXIT_FAILURE);
	data = parse_game_data(av[1]);
	if (!data)
		return (ft_error("while Setting Game data\n"), EXIT_FAILURE);
	game->data = data;
	raycaster(game);
	return (EXIT_SUCCESS);
}
