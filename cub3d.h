/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:06:26 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/17 19:56:09 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "./srcs/parsing/parser.h"

/* parsing */
t_data	*parse_game_data(char *map_path);

/* External Helper functions (from libft but with some editing on them )*/
char	*get_next_line(int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif