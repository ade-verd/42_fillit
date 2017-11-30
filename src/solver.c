/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:52:23 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/30 13:37:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	ft_newpoint(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

void	ft_lstappend(t_point *new, t_point *point)
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

int		ft_pos_x(char *src, int ref, int pos)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i] != '\n')
		{
			if (src[i] == ref)
				ref == j;
			if (src[i] == pos)
				return (j - ref);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_pos_y(int ref, int pos, int x, int size)
{
	int		y;

	y = 0;
	while (pos != (ref + x + y * (size + 1)))
		y++;
	return (y);
}

void	ft_fill_new_tm(char *src, char *dst, int size, char *letter)
{
	int		x;
	int		y;
	int		ref;
	t_point	tm;

	pos = 0;
	tm = NULL;
	while (src[pos++])
	{
		if (src[pos] == '#')
		{
			if (ref == NULL)
			{
				ref = pos;
				ft_lstappend(ft_newpoint(0, 0), tm);
			}
			else
			{
				x = ft_pos_x(src, ref, pos);
				y = ft_pos_y(ref, pos, x, size);
				ft_lstappend(ft_newpoint(x, y), tm);
			}
		}
	}
}
