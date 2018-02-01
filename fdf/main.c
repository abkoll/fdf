/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:19:23 by akoller           #+#    #+#             */
/*   Updated: 2018/01/07 18:59:39 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void *mlx;
void *win;

// int my_key_funct(int keycode, void *mlx)
// {
// 	mlx = 0;
// 	printf("key event %d\n", keycode);
// 	return (0);
// }

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 100;
	while (y<150)
	{
		x= 100;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	//mlx_key_hook(win, my_key_funct, mlx);		
	mlx_loop(mlx);
}
