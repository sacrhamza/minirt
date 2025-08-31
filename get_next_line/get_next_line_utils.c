/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:12:33 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/16 16:43:10 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	fn_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*fn_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (dest == src && dest != NULL)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

char	*fn_strchr(const char *s, int c)
{
	char	character;

	if (s == NULL)
		return (NULL);
	character = (char)c;
	while (*s != '\0')
	{
		if (*s == character)
			return ((char *)s);
		s++;
	}
	if (character == '\0')
		return ((char *)s);
	return (0);
}

char	*fn_strjoin(char *s1, char *s2, size_t *i, ssize_t n)
{
	size_t	len;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = *i + n;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (free(s1), free(s2), NULL);
	if (s1 != NULL)
		fn_memcpy(ptr, s1, *i + 1);
	if (s2 != NULL)
		fn_memcpy(ptr + *i, s2, n + 1);
	free(s1);
	*i += n;
	return (ptr);
}

char	*fn_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	if (ptr == 0)
		return (0);
	ptr = (char *)malloc((fn_strlen(s) + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	fn_memcpy(ptr, s, fn_strlen(s) + 1);
	return (ptr);
}
