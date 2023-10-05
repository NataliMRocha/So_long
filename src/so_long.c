#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 500
#define HEIGHT 500

typedef struct s_def
{
	mlx_t *mlx;
	mlx_image_t *image[3];
	mlx_texture_t *png;
} t_def;

void ft_put_pixel(uint32_t color, mlx_image_t *image)
{
	int32_t x = 0;
	int32_t y = 0;
	while (x < image->width && y < image->height)
	{
		mlx_put_pixel(image, x, y, color);
		x++;
		if(x == image->width && y < image->height)
		{	
			x = 0;
			y++;
		}
	}
}

int32_t main(int32_t argc, const char* argv[])
{
	t_def *def;
		
	def = malloc(sizeof(t_def));
	def->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	def->image[0] = mlx_new_image(def->mlx, 50, 50);
	def->image[1] = mlx_new_image(def->mlx, 50, 50);
	def->png = mlx_load_png("./chess-pieces-16x16-sprites/individual-sprites/piece1.png");
	def->image[2] = mlx_texture_to_image(def->mlx, def->png); 

	ft_put_pixel(0xF15FAFFF, def->image[0]);
	ft_put_pixel(0xF1FFFFFF, def->image[1]);
	int x = 0;
	int y = 0;
	while(y < 400)
	{
		while(x < 400)
		{
			if ((y / 50) % 2 != 0)
			{
				mlx_image_to_window(def->mlx, def->image[1], x, y);
				mlx_image_to_window(def->mlx, def->image[0], x+50, y);
			}
			else
			{	
				mlx_image_to_window(def->mlx, def->image[0], x, y);
				mlx_image_to_window(def->mlx, def->image[1], x+50, y);
			}
			x += 100;
		}
		x = 0;
		y += 50;
	}
	mlx_image_to_window(def->mlx, def->image[2], 0, 50);
	mlx_loop(def->mlx);
	mlx_terminate(def->mlx);
	return (EXIT_SUCCESS);

}
