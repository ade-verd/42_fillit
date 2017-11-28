/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:05 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/27 14:49:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_power(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		result = nb * ft_power(nb, power - 1);
	return (result);
}

int				ft_sqrt(int nb)
{
	int		sqr_test;
	int		nb_return;

	nb_return = 0;
	sqr_test = 0;
	if (nb <= 0)
		return (0);
	while (nb_return < nb)
	{
		sqr_test++;
		nb_return = ft_power(sqr_test, 2);
	}
	if (nb_return == nb)
		return (sqr_test);
	return (0);
}
