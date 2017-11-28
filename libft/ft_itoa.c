/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:27:47 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/23 17:22:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int		ft_intlen(int n)
{
	int		nb_char;
	int		sign;

	nb_char = 1;
	sign = (n < 0 ? -1 : 1);
	while (n / 10 != 0)
	{
		nb_char++;
		n = n / 10;
	}
	if (sign < 0)
		return (nb_char + 1);
	return (nb_char);
}

char			*ft_itoa(int n)
{
	char	*n_char;
	int		len;
	int		start_nb;

	len = ft_intlen(n);
	start_nb = (n < 0 ? 1 : 0);
	if ((n_char = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	n_char[len] = '\0';
	len--;
	while (len >= start_nb)
	{
		n_char[len] = ft_abs(n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (start_nb == 1)
		n_char[len] = '-';
	return (n_char);
}
