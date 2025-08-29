#include <minirt.h>
#include <parsing.h>

void parse_file(int fd)
{
  (void)fd;
}

void throw_error(char *error, t_error exit_code)
{
  write(2, "miniRt: ", 9);
  printf("%s\n", error);
  exit(exit_code);
}

bool check_file_extension(char *filename)
{
  int index;
  int len;
  char *file_extension;
  int extension_len;

  extension_len = 3;
  index = 0;
  len = strlen(filename);
  if (len < extension_len)
    return (false);
  file_extension = filename + (len - extension_len);
  if (strcmp(file_extension, ".rt") != 0)
    return (false);
  return (true);
}

void parsing(char *filename)
{
  int fd;

  fd = open(filename, O_RDONLY);
  if (fd == -1)
  {
    write(2, "miniRt: ", 9);
    perror(filename);
    exit (OPEN_FAILED);
  }
  if (!check_file_extension(filename))
  {
    close(fd);
    throw_error(FILE_EXTENSION_ERROR, EXTENSION_ERROR);
  }
  parse_file(fd);
  close(fd);
}
