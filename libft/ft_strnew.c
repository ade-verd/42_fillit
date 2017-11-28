/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:15:25 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/22 16:04:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		*ft_memalloc(size_t size)
{
	void	*p;
	char	*s;

	if ((p = (void*)malloc(size)) == NULL)
		return (NULL);
	s = (char*)p;
	while (size--)
		*s++ = 0;
	return (p);
}

char			*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char*)ft_memalloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	s[size] = '\0';
	return (s);
}
