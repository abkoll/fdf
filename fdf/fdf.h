/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:46:18 by akoller           #+#    #+#             */
/*   Updated: 2018/01/05 16:06:03 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# include "src/libft/libft.h"
# include "src/libmlx/mlx.h"

# define ESC	53

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		xmid;
	int		ymid;
	int		big;
	int		gap;
	int		zmax;
	int		zmin;
	int		**grid;
	float	wx;
	float	wy;
	float	wz;
	float	modz;
}			t_map;

typedef struct s_parse
{
	char	*str;
	char	*line;
	char	**coord;
}			t_parse;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		ww;
	int		wh;
	t_map	**plane;
}			t_window;

typedef struct s_env
{
	t_map		*m;
	t_window	*w;
	t_parse		*p;
}			t_env;


void	ft_parse(char *av, t_env *env);
void	ft_map(char *av, t_env *env);
void	ft_window(t_env *env);

#endif