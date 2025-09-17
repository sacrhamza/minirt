#include <parsing.h>
#include <stdio.h>
#include <minirt.h>

int main(int argc, char *argv[], char **envp)
{
  if (argc != 2)
  {
    throw_error(ARGUMENT_NBR_ERROR, NOT_VALID_NBR);
  }
  else {
    parsing(argv[1]);
    render(envp);
  }
  return (0);
}
