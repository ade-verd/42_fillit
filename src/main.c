/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/04 09:26:39 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		size;

	size = 2;
	if (ac == 2)
	{
		if ((fd = open(av[1], 0, O_RDONLY)) == -1)
		{
			ft_putstr_fd("error open().\n", 2);
			return (-1);
		}
		ft_run_solver(fd, 'A', size);
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
	return (0);
}
