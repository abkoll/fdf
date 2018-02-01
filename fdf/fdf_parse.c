/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:33:01 by akoller           #+#    #+#             */
/*   Updated: 2017/11/30 13:39:00 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(int fd, int w, int i, t_env *env)
{
	if (get_next_line(fd, &(env->p->line)))
	{
		ft_mapcheck(env->p->line);
		if ((env->p->coord = ft_strsplit(env->p->line, ' ')) == NULL)
			ft_error("Error: content");
		if (!(w = ft_wdcnt(env->p->coord)))
		 	ft_error("Error: line");
		env->m->x = w;
		i = 1;
		free(env->p->line);
		free(env->p->coord);
	}
	else
		ft_error("Error: empty file");
	while (get_next_line(fd, &(env->p->line)))
	{
		ft_mapcheck(env->p->line);
		if ((env->p->coord = ft_strsplit(env->p->line, ' ')) == NULL)
			ft_error("Error: content");
		if (ft_wdcnt(env->p->coord) != w)
			ft_error("Error: size uneven");
		i++;
		free(env->p->line);
	}
	env->m->y = i;
}

void	ft_parse(char *av, t_env *env)
{
	int		fd;
	int		w;
	int		i;

	w = 0;
	i = 0;
	if ((env->p->str = ft_strstr(av, ".fdf")) == 0)
		ft_error("Error: improper file");
	if ((fd = open (av, O_RDONLY)) < 0)
		ft_error("Error: no file");
	ft_line(fd, w, i, env);
}