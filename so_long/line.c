

char	*wall_path;
char	*ground_path;
void	*img;
void	*img2;
int		width;
int		height;
int		i;
int		j;

wall_path = "./Sprite/wall2.xpm";
ground_path = "./Sprite/Ground.xpm";

width = 50;
height = 50;
img2 = mlx_xpm_file_to_image(vars.mlx, ground_path, &width, &height);
img = mlx_xpm_file_to_image(vars.mlx, wall_path, &width, &height);
while (j < 600)
{
	i = 0;
	mlx_put_image_to_window(vars.mlx, vars.win, img, i, j);
	i = 50;
	while (i < 600)
	{
		if (j == 0)
			mlx_put_image_to_window(vars.mlx, vars.win, img, i, j);
		else
			mlx_put_image_to_window(vars.mlx, vars.win, img2, i, j);
		i += 50;
		mlx_put
	}
	j += 50;
}
mlx_
