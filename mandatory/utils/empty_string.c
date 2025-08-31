#include <minirt.h>

bool	char_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

bool empty_string(char *line)
{
  while (*line)
  {
    if (!char_in_set(*line, SPACES))
      return (false);
    line++;
  }
  return (true);
}
