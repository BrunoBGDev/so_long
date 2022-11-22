/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:53:05 by bbraga            #+#    #+#             */
/*   Updated: 2022/11/22 16:38:26 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_get_line(char *stack);
char	*get_next_line(int fd);
char	*ft_stringchr(char *s, int c);
char	*ft_stringjoin(char *stack, char *buff);
size_t	ft_stlen(const char *s);

#endif
