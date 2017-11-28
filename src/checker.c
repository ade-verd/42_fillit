/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:47:05 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/27 18:39:42 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_square(char *str)
{
	int		i;
	int		hashtag;
	int		point;
	int		endline;

	hashtag = 0;
	point = 0;
	endline = 0;
	i = 0;
	while (str[i++])
	{
		if (str[i] == '#')
			hashtag++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			endline++;
	}
	if (hashtag == 4 && point == 12 && endline == 4)
		return (1);
	return (0);
}


