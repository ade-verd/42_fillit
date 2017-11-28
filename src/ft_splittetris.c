/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:32:02 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 16:37:27 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description
** Split each tetriminos in an array of char*.
** The initial string doesn't need to be valid. Tests are made after that.
**
** Return
** char** : Array of each Tetriminos
*/

#include "fillit.h"
#include "libft.h"

static int		ft_count_tm(char const *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		*ft_extract_tm(char const *s, int start)
{
	int		i;
	int		end;
	char	*tm;

	i = 0;
	end = start;
	while (s[end] && s[end] != '\n' &&
			(s[end + 1] != '\n' || s[end + 1] != '\0'))
			end++;
	if ((tm = (char*)malloc(sizeof(char) * (end - start + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0' && start <= end)
	{
		tm[i] = s[start];
		start++;
		i++;
	}
	tm[i] = '\0';
	return (tm);
}

char**			ft_splittestris(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		len;
	char	*tm;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ft_count_tm(str) + 1)) == NULL)
		return (NULL);
	while (i < ft_count_tm(str))
	{
		tm = ft_extract_tm(str, j);
		len = ft_strlen(tm);
		if ((tab[i] = (char*)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		tab[i] = tm;
		j = j + len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
