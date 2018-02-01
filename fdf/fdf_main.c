/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:29:10 by akoller           #+#    #+#             */
/*   Updated: 2017/11/30 13:32:41 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map 		*init_map(void)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->xmid = 0;
	map->ymid = 0;
	map->big = 0;
	map->gap = 0;
	map->zmax = 0;
	map->zmin = 0;
	map->grid = NULL;
	return(map);
}

t_parse		*init_parse(void)
{
	t_parse	*parse;

	parse = (t_parse*)malloc(sizeof(t_parse));
	parse->str = NULL;
	parse->line = NULL;
	parse->coord = NULL;
	return(parse);
}

t_window	*init_window(void)
{
	t_window	*window;
	
	window = (t_window*)malloc(sizeof(t_window));
	window->mlx = NULL;
	window->win = NULL;
	return(window);
}

t_env		*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->p = init_parse();
	env->m = init_map();
	env->w = init_window();
	return(env);
}




int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_error("Error: not enough arguments");
	env = init_env();
	ft_parse (av[1], env);
	ft_map (av[1], env);
	// printf("c main\n");
	ft_center (env);
	// printf("c main\n");
	// ft_window(env);
	//fdf = ft_makeenvironment(map);
	//ft_draw(fdf, fdf->hooks);
	
	// void	*win;
	// //int	x;
	// void	*mlx; 
	// //int y;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 700, 700, "wind");
	// 		mlx_pixel_put(mlx, win, 100, 100, 0x00991001);
	// mlx_loop(mlx);
}

// void	ft_open()
// {
// 	void	*mlx;
// 	void	*win;
// }