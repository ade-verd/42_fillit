/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contiguous_pieces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:26:31 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 12:07:10 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description
** A valid Tetriminos have 4 pieces which are contiguous by at least one side.
** ft_contiguous_places checks for each '#' if the piece is isolated or not.
**
** Return
** Tetriminos valid = 1
** Tetriminos invalid = 0
*/

static int	ft_isnot_lonely(char *str, int pos)
{
	if (str[pos - 1] && str[pos - 1] == '#')
		return (1);
	if (str[pos + 1] && str[pos + 1] == '#')
		return (1);
	if (str[pos - 5] && str[pos - 5] == '#')
		return (1);
	if (str[pos + 5] && str[pos + 5] == '#')
		return (1);
	return (0);
}

int			ft_contiguous_pieces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (ft_isnot_lonely(str, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
