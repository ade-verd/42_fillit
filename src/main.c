/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/29 12:19:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*file;
	char	**tab;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("error open().\n", 2);
			return (-1);
		}
		file = ft_read_buff(fd);
		tab = ft_splittetris(file);
		if (ft_check_all(tab) == 0)
		{
			ft_putstr_fd("error\n", 2);
			return (-1);
		}
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr_fd("error\n", 2);// USAGE A METTRE
	return (0);
}
