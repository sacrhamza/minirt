#include <get_next_line.h>
#include <minirt.h>
#include <parsing.h>

void set_ambient(char **info_type)
{
  (void)info_type;

  printf("ambient");
}
void set_camera(char **info_type)
{
  (void)info_type;
  printf("camera");
}

void set_light(char **info_type)
{
  (void)info_type;

  printf("light");
}

void set_sphere(char **info_type)
{
  (void)info_type;

  printf("sphere");
}

void set_plane(char **info_type)
{
  (void)info_type;

  printf("plane");
}

void set_cynlinder(char **info_type)
{
  (void)info_type;

  printf("cynlinder");
}

t_elem_handler *get_element_handlers(void)
{
  static t_elem_handler element_handlers[6];

   element_handlers[0] = (t_elem_handler){.key = "A", .func = set_ambient};
   element_handlers[1] = (t_elem_handler){.key = "C", .func = set_camera};
   element_handlers[2] = (t_elem_handler){.key = "L", .func = set_light};
   element_handlers[3] = (t_elem_handler){.key = "sp", .func = set_sphere};
   element_handlers[4] = (t_elem_handler){.key = "pl", .func = set_plane};
   element_handlers[5] = (t_elem_handler){.key = "cy", .func = set_cynlinder};

  return (element_handlers);
}

t_elem_handler *get_proper_handler(char *key, t_elem_handler *element_handlers)
{
  int index;

  index = 0;
  while (index <= 5)
  {
    if (strmatch(element_handlers[index].key, key))
      return (element_handlers + index);
    index++;
  }
  return (NULL);
}

void add_type_element(char *line, t_elem_handler *element_handlers)
{
  size_t index;
  char **fields;
  t_elem_handler *proper_handler;

  index = 0;
  fields = ft_split(line, ' ');
  print_strings(fields);
  proper_handler = get_proper_handler(fields[0], element_handlers);
  if (proper_handler != NULL)
    proper_handler->func(fields);
  else
   throw_error("hey", 1);
}

void parse_scene_file(int fd)
{
  char *line;
  t_elem_handler *element_handlers;

  element_handlers = get_element_handlers();
  line = get_next_line(fd);
  if (line == NULL)
    exit (5);
  while (line)
  {
    if (!empty_string(line))
      add_type_element(line, element_handlers);
    free(line);
    line = get_next_line(fd);
  }
}
