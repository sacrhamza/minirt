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

typedef struct s_elem_handler
{
  char *key;
  void (*func)(char **info_type);
} t_elem_handler;

void parsing(char *filename);
void parse_scene_file(int fd);
void throw_error(char *error, t_error exit_code);

typedef struct s_point
{
  float x;
  float y;
  float z;
}t_coordinate;

typedef struct s_color
{
  int red;
  int green;
  int blue;
}t_color;

typedef struct s_ambient
{
  float lighting_ration;
  t_color color;
}t_ambient;

typedef struct s_camera
{
  t_coordinate viewpoint;
  int fov;
}t_camera;

typedef struct s_light
{
  t_coordinate light_point;  
  float brightnes_ratio;
}t_ligth;

typedef struct s_sphere
{
  t_coordinate center;
  int diameter;
  t_color color;
}t_sphere;

typedef struct s_plane{
  t_coordinate point;
  t_color color;
}t_plane;

typedef struct s_cylinder{
  t_coordinate center;
  float diameter;
  t_color color;
}t_cylinder;

#endif
