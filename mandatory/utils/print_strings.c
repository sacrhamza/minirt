#include <minirt.h>

void print_strings(char **strings)
{
  size_t index;

  index = 0;
  while (strings[index])
  {
    printf("%ld: \"%s\"\n", index + 1, strings[index]);
    index++;
  }
}
