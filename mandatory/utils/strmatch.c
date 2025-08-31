/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:29:31 by hsacr             #+#    #+#             */
/*   Updated: 2025/07/14 17:29:31 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	strmatch(const char *string_1, const char *string_2)
{
  size_t	index;

  index = 0;
  if (string_1 == NULL || string_2 == NULL)
    return (false);
  while (string_1[index] && (unsigned char)string_1[index] == (unsigned char)string_2[index])
  {
    index++;
  }
  return (((unsigned char)string_1[index] - (unsigned char)string_2[index]) == 0);
}
