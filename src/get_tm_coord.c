/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tm_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:05:02 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/30 16:11:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*ft_newpoint(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->next = NULL;
	return (point);
}

static void		ft_lstappend(t_point *new, t_point *point)
{
	t_point		*current;

	if (point && new)
	{
		current = point;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}

static int		ft_pos_x(char *src, int ref, int pos)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i] != '\n')
		{
			if (i == ref)
				ref = j;
			if (i == pos)
				return (j - ref);
			i++;
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_pos_y(int ref, int pos, int x, int size)
{
	int		y;

	y = 0;
	while (pos != (ref + x + y * (size + 1)))
		y++;
	return (y);
}

t_point			*ft_get_coord_tm(char *src, int size)
{
	int		pos;
	int		x;
	int		y;
	int		ref;
	t_point	*tm;

	ref = -1;
	pos = -1;
	tm = ft_newpoint(0, 0);
	while (src[++pos])
	{
		if (src[pos] == '#')
		{
			if (ref == -1)
				ref = pos;
			else
			{
				x = ft_pos_x(src, ref, pos);
				y = ft_pos_y(ref, pos, x, size);
				ft_lstappend(ft_newpoint(x, y), tm);
			}
		}
	}
	return (tm);
}
