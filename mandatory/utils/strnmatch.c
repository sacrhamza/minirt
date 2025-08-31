/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:29:35 by hsacr             #+#    #+#             */
/*   Updated: 2025/07/14 17:29:36 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	strnmatch(const char *string_1, const char *string_2, size_t n)
{
  size_t index;

  if (string_1 == NULL || string_2 == NULL)
    return (false);
  index = 0;
  while (index < n && string_1[index] && string_2[index])
  {
    if (string_1[index] != string_2[index])
      return (false);
    index++;
  }
  return (index == n);
}
