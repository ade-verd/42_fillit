/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:48:52 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/30 10:49:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_create_empty_map(int side)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = side * side + side;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{	
		j = 0;
		while (j < side)
		{
			str[i] = '.';
			i++;
			j++;
		}
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}
