#include <get_next_line.h>
#include <minirt.h>
#include <parsing.h>

// bool empty_scene_line(char *line)
// {
//   return (line == NULL || empty_string(line));
// }

struct s_elem_id
{
  char *id;
  void (*func)(char *info_type);
};

void set_ambient(char *info_type)
{

}
void set_camera(char *info_type)
{

}

void set_light(char *info_type)
{

}



struct s_elem_id *set_func(void)
{
  static struct s_elem_id elem_id[6];

   elem_id[0] = (struct s_elem_id){.id = "A", .func = set_ambient};
   elem_id[1] = (struct s_elem_id){.id = "C", .func = set_camera};
   elem_id[2] = (struct s_elem_id){.id = "L", .func = set_light};
   elem_id[3] = (struct s_elem_id){.id = "sp", .func = set_light};
   elem_id[4] = (struct s_elem_id){.id = "pl", .func = set_light};
   elem_id[5] = (struct s_elem_id){.id = "cy", .func = set_light};

  return (elem_id);
}

void add_type_element(char *line)
{
  size_t index;
  char **elements;

  index = 0;
  elements = ft_split(line, ' ');
  print_strings(elements);
  set_func();
}

void parse_scene_file(int fd)
{
  char *line;

  line = get_next_line(fd);
  if (line == NULL)
    exit (5);
  while (line)
  {
    if (!empty_string(line))
      add_type_element(line);
    free(line);
    line = get_next_line(fd);
  }
}
