/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/29 11:02:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*file;
	char	**tab;
	int		tm_nb;

	tm_nb = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("error open().\n");
			return (-1);
		}
		file = ft_read_buff(fd);
		tab = ft_splittetris(file);
		while(tab[tm_nb])
		{
			ft_putstr(tab[tm_nb]);
			ft_putstr("------\n");
			tm_nb++;
		}
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr("error\n");
	return (0);
}
