/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:17:02 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/20 07:19:36 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
			counter++;
		i++;
	}
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			len;
	char			**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		if ((s[i] != c && (s[i - 1] == c)) || (i == 0 && s[i] != c))
		{
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			tab[j++] = ft_strsub(s, i, len);
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
