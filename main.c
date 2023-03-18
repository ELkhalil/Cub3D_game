/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:37 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:49:13 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_error(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    if (msg)
        ft_putstr_fd(msg, 2);
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 1 || ac > 2 || ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
        return (ft_error("Invalid arguments\n"), EXIT_FAILURE);
    data = parse_game_data(av[1]);
    if (!data)
        return (ft_error("while Setting Game data\n"), EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
