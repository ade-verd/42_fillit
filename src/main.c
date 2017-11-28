/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/28 15:47:49 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buf[21];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_putstr("No such file.\n");
		else
		{
			read(fd, buf, 21);
			buf[20] = '\0';
			printf("buf:\n%s\n", buf);
			close(fd);
		}
	}
	else
		ft_putstr("error\n");
	return (0);
}
