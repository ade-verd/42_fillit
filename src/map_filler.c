/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:19:29 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/01 15:54:00 by oozkaya          ###   ########.fr       */
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

/*int		ft_moveto(char *map, int dir, char letter)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == letter)
		{
			if (!map[i] || map[i + dir] == '\n')
				return (0);
			if (map[i + dir] == )
		}
		i++;
	}
	return (1)
}*/

char	*ft_solver(t_point **tm, char *map, int pos, int size, int i)
{
	if (!tm[i])
		return (map);
	if (ft_placement(tm[i], map, pos, size) == 1)
	{
		printf("%s---------\n", map);
		return (ft_solver(tm, map, 0, size, i + 1));
	}
	while (tm[i])
	{
		if (ft_placement(tm[i], map, pos, size) == 1)
			return(ft_solver(tm, map, 0, size, i + 1))
		tm[i++];
	}
	/*else
	{
		if (!map[pos + 1] && !tm[i + 1])
		{
			size++;
			map = ft_create_empty_map(size);
			i = 0;
			pos = -1;
		}
		else if (map[pos + 1] && tm[i - 1])
		{
			ft_del_current(map, tm[i - 1]->letter);
			i--;
		}
		return (ft_solver(tm, map, pos + 1, size, i));
	}*/
	return (NULL);
}
