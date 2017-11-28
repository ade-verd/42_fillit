/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:16:31 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/20 13:35:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		start;
	char	*point;

	i = 0;
	point = NULL;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		start = i;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (point = (char*)&haystack[start]);
			j++;
		}
		i++;
	}
	return (point);
}
