/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:19:29 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/01 17:14:21 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_del_current(char *map, char letter)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == letter)
			map[i] = '.';
		i++;
	}
}

int		ft_placement(t_point *tm, char *map, int pos, int size)
{
	int		i;

	while (tm)
	{
		i = pos + tm->x + (tm->y * (size + 1));
		if (!(map[i]) || map[i] != '.')
		{
			ft_del_current(map, tm->letter);
			return (0);
		}
		map[i] = tm->letter;
		tm = tm->next;
	}
	return (1);
}

int		ft_solver(t_point **tm, char *map, int pos, int size, int i)
{
	if (!tm[i])
	{
		printf("%s---------\n", map);
		return (1);
	}
	while (tm[i])
	{
		pos = 0;
		while (map[pos])
		{
			if (ft_placement(tm[i], map, pos, size) == 1 && 
					ft_solver(tm, map, 0, size, i + 1) == 1)
			{
				printf("%s---------\n", map);
				return (1);
			}
			pos++;
		}
		//ft_del_current(map, tm[i]->letter);
		i++;
	}
	return (ft_solver(tm, ft_create_empty_map(size + 1), 0, size + 1, 0));
}
