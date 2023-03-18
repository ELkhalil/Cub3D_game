/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:59:06 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:54:08 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*Map Storage infos*/
typedef struct map_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
}			t_data;

/* gobal functions */
void	ft_error(char *msg);

/* reading functions */
char	*get_next_line(int fd);

/* parsing functions */
void	init_data(t_data **data);
int		extract_colors(t_data **data, char *line, int flag);
int		is_valid_num(char *num);
int		count_char(char *str, char c);
int		count_sc(char **arr);

/* memory cleaning functions */
void	free_array(char **strs);

#endif