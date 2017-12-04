/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:10:40 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/04 14:40:51 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_all(t_point **t_tab, char *str, char *map)
{
	int		i;
	void	*tmp;

	i = 0;
	while (t_tab[i])
	{
		while (t_tab[i])
		{
			tmp = t_tab[i]->next;
			free((void**)t_tab[i]);
			t_tab[i] = tmp;
		}
		i++;
	}
	ft_memdel((void**)&t_tab);
	ft_memdel((void**)&str);
	ft_memdel((void**)&map);
}
