/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:11:20 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/29 18:13:07 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_resize_map(char *str)
{
	int		i;
	int		src;
	int		dst;
	char	*tmp;
	int		size;

	i = 0;
	size = 0;
	while (str[i++])
		if (str[i] == '\n')
			size++;
	tmp = ft_strdup(str);
	ft_memdel((void**)&str);
	str = ft_create_empty_map(size + 1);
	src = -1;
	dst = 0;
	while (tmp[++src])
	{
		i = 0;
		while (i++ < size)
			str[dst++] = tmp[src++];
		dst = dst + 2;
	}
	ft_memdel((void**)&tmp);
	return (str);
}
