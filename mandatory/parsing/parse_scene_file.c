#include <get_next_line.h>
#include <minirt.h>
#include <parsing.h>

typedef struct s_elem_handler
{
  char *key;
  void (*func)(char **info_type);
} t_elem_handler;

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

t_elem_handler *set_func(void)
{
  static t_elem_handler elem_id[6];

   elem_id[0] = (t_elem_handler){.key = "A", .func = set_ambient};
   elem_id[1] = (t_elem_handler){.key = "C", .func = set_camera};
   elem_id[2] = (t_elem_handler){.key = "L", .func = set_light};
   elem_id[3] = (t_elem_handler){.key = "sp", .func = set_light};
   elem_id[4] = (t_elem_handler){.key = "pl", .func = set_light};
   elem_id[5] = (t_elem_handler){.key = "cy", .func = set_light};

  return (elem_id);
}

t_elem_handler *get_proper_handler(char *key, t_elem_handler *element_handlers)
{
  int index;

  index = 0;
  while (index <= 5)
  {
    if (strmatch(element_handlers[index].key, key) == 0)
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

  element_handlers = set_func();
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
