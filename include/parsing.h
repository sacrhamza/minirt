#ifndef PARSING_H
# define PARSING_H
# define ARGUMENT_NBR_ERROR "ERROR: number of argument not valid, \
expected: 1 argument => file.rt"
# define FILE_EXTENSION_ERROR "filename should have .rt extension"
# define SPACES "\n\t "

typedef enum e_error
{
  OPEN_FAILED = 1,
  EXTENSION_ERROR = 1,
  NOT_VALID_NBR = 1
} t_error;

void parsing(char *filename);
void parse_scene_file(int fd);
void throw_error(char *error, t_error exit_code);
#endif
