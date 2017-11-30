/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/30 17:38:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		fd;
	char	*file;
	char	**tab;
	char	point;
	char	letter;
	char	*map;
	t_point	*p;

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
		i = 0;
		j = 0;
		letter = 'A';
		map = ft_create_empty_map(4);
		while (tab[i])
		{
			point = 'a';
			printf("%s--------\n", tab[i]);
			p = ft_get_coord_tm(tab[i], 4, letter++);
			//while (p)
			//{
			//	printf("%s\n--------\n", map);
				while (ft_placement(p, map, j, 4) != 1 && map[j])
					j++;
		//		printf("%c\t point %c : x:%d y:%d\n", p->letter, point, p->x, p->y);
		//		p = p->next;
		//		point++;
		//	}
				printf("%s--------\n", map);
			i++;
		}
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr_fd("error\n", 2);// USAGE A METTRE
	return (0);
}
