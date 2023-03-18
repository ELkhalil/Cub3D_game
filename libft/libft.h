/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:31:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:48:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* Get Next Line Settings*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

/* functions prototypes */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char *str);

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
void	ft_putstr(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(char *s1);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
