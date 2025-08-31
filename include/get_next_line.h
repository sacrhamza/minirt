/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:12:55 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/16 15:35:08 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2999
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*fn_substr(char const *s, unsigned int start, size_t len);
char		*get_line(int fd, char **buffer, char **pretty_name);
char		*get_next_line(int fd);
void		fn_handle(char **buffer, char **pretty_name);
size_t		fn_strlen(const char *s);
void		*fn_memcpy(void *dest, const void *src, size_t n);
char		*fn_strchr(const char *s, int c);
char		*fn_strdup(const char *s);
char		*fn_strjoin(char *s1, char *s2, size_t *i, ssize_t n);
#endif
