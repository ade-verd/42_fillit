/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:05:30 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/29 12:18:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_onetm(char *str)
{
	int		i;
	int		hashtag;
	int		point;
	int		endline;

	hashtag = 0;
	point = 0;
	endline = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hashtag++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			endline++;
		i++;
	}
	if (hashtag == 4 && point == 12 && endline == 4)
		return (1);
	return (0);
}

int			ft_check_all(char **tab)
{
	int		tm_nb;

	tm_nb = 0;
	while (tab[tm_nb])
	{
		if (ft_check_onetm(tab[tm_nb]) == 0)
			return (0);
		tm_nb++;
	}
	return (1);
}
