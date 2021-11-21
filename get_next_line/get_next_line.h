/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:48:02 by rtwitch           #+#    #+#             */
/*   Updated: 2021/11/20 18:17:09 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*make_line(int fd, char *str);
char	*get_first_line(char *line);
char	*get_last_line(char *line);
char	*get_null(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
