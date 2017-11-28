/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:45:40 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/20 07:19:07 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_end(char const *s, int len)
{
	int		end;

	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == 0)
		len--;
	end = len;
	return (end);
}

static int	ft_start(char const *s, int len)
{
	int		i;
	int		start;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		len--;
		i++;
	}
	start = i;
	return (start);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	end = ft_end(s, len);
	start = ft_start(s, len);
	if (!(new = (char*)malloc(sizeof(*new) * (len / 2))))
		return (NULL);
	i = 0;
	while (start <= end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
