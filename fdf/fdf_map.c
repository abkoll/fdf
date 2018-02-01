/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:44:21 by akoller           #+#    #+#             */
/*   Updated: 2017/12/22 15:44:27 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		**ft_plane(t_env *e)
{
	t_map	**g;
	int		i;
	int		j;

	i = 0;
	g = ft_memalloc(sizeof(int *) * (e->m->y + 1));
	while (i < e->m->y)
	{
		g[i] = ft_memalloc(sizeof(int) * (e->m->x + 1));
		j = 0;
		while (j < e->m->x)
		{
			g[i][j].wx = (j - e->m->xmid) * e->m->gap;
			g[i][j].wy = (i - e->m->ymid) * e->m->gap;
			g[i][j].wz = e->m->grid[i][j];
			g[i][j].modz = e->m->grid[i][j] * 5;
			j++;
		}
		i++;
	}
	i++;
	g[i] = NULL;
	return(g);
}

void	ft_structure(t_env *e)
{
	e->m->big = e->m->x > e->m->y ? e->m->x : e->m->y;
	e->m->gap = 600 / e->m->big;
	e->m->xmid = e->m->x / 2;
	e->m->ymid	= e->m->y / 2;
	e->w->mlx = mlx_init;
	e->w->win = mlx_new_window(w->mlx, e->w->ww, e->w->wh, "fdf");
	e->w->ww = 200 + (e->m->gap * e->m->x);
	e->w->wh = 200 + (e->m->gap * e->m->y);
}

int		*ft_row(char **c, int x)
{
	int		*grid;
	int		i;

	i = 0;
	grid = 0;
	grid = ft_memalloc(sizeof(int) * (x + 1));
	while (i < x)
	{
		grid[i] = ft_atoi(&c[i][0]);
		i++;
	}
	return (grid);
}

void	ft_z(int fd, t_map *m)
{
	int		r;
	int		c;
	char	**coord;
	char	*line;

	c = 0;
	r = 0;
	m->zmax = 0;
	m->zmin = 0;
	m->grid = ft_memalloc(sizeof(int *) * (m->y + 1));
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		m->grid[r] = ft_row(coord, m->x);
		free(coord);
		free(line);
		while (c < m->x)
		{
			m->zmax = m->grid[r][c] > m->zmax ? m->grid[r][c] : m->zmax;
			m->zmin = m->grid[r][c] < m->zmin ? m->grid[r][c] : m->zmin;
			c++;
		}
		r++;
	}
	close(fd);
}

void	ft_map(char *av, t_env *env)
{
	int		fd;

	fd = open(av, O_RDONLY);
	ft_z(fd, env->m);
	ft_structure(env);
	env->w->plane = ft_plane(env);
}