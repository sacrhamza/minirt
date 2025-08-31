/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:37 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/16 18:53:29 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fn_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (start > fn_strlen(s))
		start = fn_strlen(s);
	if (fn_strlen(s + start) < len)
		len = fn_strlen(s + start);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	fn_memcpy(ptr, s, len);
	ptr[len] = '\0';
	return (ptr);
}

char	*get_line(int fd, char **buffer, char **pretty_name)
{
	ssize_t	n;
	size_t	i;

	i = fn_strlen(*buffer);
	while (fn_strchr(*buffer, '\n') == NULL)
	{
		n = read(fd, *pretty_name, BUFFER_SIZE);
		(*pretty_name)[n] = '\0';
		if (n < 0)
			return (free(*pretty_name), free(*buffer),
				*buffer = NULL, *pretty_name = NULL);
		*buffer = fn_strjoin(*buffer, *pretty_name, &i, n);
		if (*buffer == NULL)
			return (*pretty_name = NULL);
		if (n < BUFFER_SIZE)
			break ;
	}
	fn_handle(buffer, pretty_name);
	if (*pretty_name != NULL && **pretty_name == '\0')
	{
		free(*pretty_name);
		*pretty_name = NULL;
	}
	return (*pretty_name);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*pretty_name;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL);
	pretty_name = malloc((BUFFER_SIZE) * sizeof(char) + 1 * sizeof(char));
	if (pretty_name == NULL)
		return (free(buffer), buffer = NULL);
	return (get_line(fd, &buffer, &pretty_name));
}

void	fn_handle(char **buffer, char **pretty_name)
{
	char	*tmp;
	char	*line_addr;

	free(*pretty_name);
	tmp = NULL;
	line_addr = fn_strchr(buffer[0], '\n');
	if (line_addr)
	{
		*pretty_name = fn_substr(buffer[0], 0,
				line_addr - buffer[0] + 1);
		if (*pretty_name && line_addr[1])
			tmp = fn_strdup(line_addr + 1);
	}
	else
		*pretty_name = fn_strdup(buffer[0]);
	free(buffer[0]);
	if (tmp != NULL && tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	*buffer = tmp;
}
