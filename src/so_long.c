/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2022/12/07 15:50:19 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	//t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc == 2)
	{
		(void)argv;
		//map = map_checker(argv[1]);
		//printf("puntero listas %p\n", map);
		//t_map	*curr = map;
		//while (curr != NULL)
		//{
		//	printf("linea: %p\n", curr->next);
		//	curr = curr->next;
		//}
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 800, 450, "Hello World!");
		img.img = mlx_new_image(mlx, 800, 450);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		for (size_t i = 0; i < 200; i++)
		{
			ft_mlx_pixel_put(&img, i, 50, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 51, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 52, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 53, 0x00FF0000);
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	else
		write(2, "Not enough arguments!\n", 23);
	return (0);
}
