#include <parsing.h>
#include <stdio.h>
#include <minirt.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    throw_error(ARGUMENT_NBR_ERROR, NOT_VALID_NBR);
    pow(3, 4);
  }
  else {
    parsing(argv[1]);
  }
  return (0);
}
