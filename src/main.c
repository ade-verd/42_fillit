/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/28 16:08:51 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[11];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("No such file.\n");
			return (1);
		}
		ret = read(fd, buf, 10);
		while (ret)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
			ret = read(fd, buf, 10);
		}
		if (close(fd) == -1)
			return (1);
	}
	else
		ft_putstr("error\n");
	return (0);
}
