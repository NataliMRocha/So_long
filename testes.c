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