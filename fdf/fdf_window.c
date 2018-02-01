/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:19:58 by akoller           #+#    #+#             */
/*   Updated: 2018/01/18 19:48:19 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// int 	ft_myfunc(t_window *w)
// {
// 	int		i;
// 	int		j;
// 	// printf("c\n");

// 	i = -1;
// 	j = -1;
// 	while (i <= w->m->x)
// 	{
// 		mlx_pixel_put(w->mlx, w->win, i + (w->m->gap), j + (w->m->gap), 0x00FFFFFF);
// 		i++;
// 		//printf("%d\n", w->m->x);

// 	}
// //		printf("e\n");

// 	return(0);
// }

//	void		ft_helptext(t_env *env)
// {
// 	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF ,"+ to zoom in");
// 	mlx_string_put(env->mlx, env->win, 10, 30, 0xFFFFFF ,"- to zoom out");
// 	mlx_string_put(env->mlx, env->win, 10, 50, 0xFFFFFF ,"ESC to Quit");
// }

// void	ft_window(t_map *m)
// {
// 	t_window *w;

// 	w = NULL;
// 	w = ft_memalloc(sizeof(t_window));
// 	//w = (t_window *)malloc(sizeof(t_window));
// 	ww = 200 + (m->gap * m->x);
// 	wh = 200 + (m->gap * m->y);

// 	printf("a\n");
// 	w->m = m;
// 	w->mlx = mlx_init();
// 	printf("b\n");
// 	w->win = mlx_new_window(w->mlx, e->w->ww, e->w->wh, "fdf");
// 	printf("c\n");
// 	mlx_expose_hook(w->win, ft_myfunc, &w);
//	ft_helptext(env);
// 	mlx_loop(w->mlx);
// }
