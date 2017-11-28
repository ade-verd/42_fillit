/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/28 17:13:48 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*file;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("error open().\n");
			return (-1);
		}
		file = ft_read_buff(fd);
		ft_putstr(file);
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr("error\n");
	return (0);
}
