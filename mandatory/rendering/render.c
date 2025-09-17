#include <fcntl.h>
#include <minirt.h>
#include <rendering.h>
#include <utils.h>


typedef struct	s_data {
  void	*img;
  char	*addr;
  int		bits_per_pixel;
  int		line_length;
  int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char	*dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}
char **env(char **envp)
{
  static char **var;
  if (envp)
    var = envp;
  return (var);
}

void rerender(void)
{
 struct timeval current;
  gettimeofday(&current, NULL);
  struct stat st;
  while (1)
  {
    // int fd = open("/tmp/output", O_RDONLY);
    // system("make > /tmp/output");
    // char res[3] = {0};
    // read(fd, res, 2);
    // if (strmatch(res, "OK"))
    // {
      // close(fd);
    system("make");
    stat("./miniRt", &st);
    if (st.st_mtim.tv_sec > current.tv_sec)
    {
      execve("./miniRt", (char *[]){"./miniRt", "./rt/scene.rt", NULL}, env(NULL));
      perror("");
    }
    // }
    // close(fd);
    usleep(10000);
  }
}

int end(void *param)
{
  (void)param;

  // exit (0);
  return (1);
}

void draw(void *mlx, t_data *img, void *win)
{
  int x, y;
  x = y = 0;

  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH) {
      // int color = ((float)(x + y) / 800) *  & 0xff) << 16;
      // int red = ((int)((float)(x + y) / (WIDTH + HEIGHT) * 0xff));
      // int green = (0xff - red) << 8;
      int red, green;
      green = 128 * x / WIDTH;
      green = 255 - y  * 255 / HEIGHT - (x * 100 / WIDTH);
      red = y * 0xf0 / HEIGHT;

      my_mlx_pixel_put(img, x, y, 0x0000f0f0);
      x++;
    }
    y++;
  }
  mlx_put_image_to_window(mlx, win, img->img, 0, 0);
  rerender();
}

void render(char **envp)
{
  void *mlx;
  void *window;
  t_data img;


  env(envp);
  mlx = mlx_init();
  window = mlx_new_window(mlx, WIDTH, HEIGHT, WINDOW_NAME);
  img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                               &img.endian);
  draw(mlx, &img, window);
  mlx_hook(window, 17, 0, end, envp);
  mlx_loop(mlx);
}
