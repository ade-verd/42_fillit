/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/01 14:58:27 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*file;
	char	**tab;
	char	letter;
	char	*map;
	int		nb_tm;
	t_tetri	*tetri;
	t_point	**t_tab;

	tetri = NULL;
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
		nb_tm = ft_count_tm(file);
		if (ft_check_all(tab) == 0)
		{
			ft_putstr_fd("error\n", 2);
			return (-1);
		}
		i = 0;
		letter = 'A';
		map = ft_create_empty_map(2);
		if (!(t_tab = (t_point**)malloc(sizeof(**t_tab) * nb_tm + 1)))
			return (0);
		t_tab[nb_tm] = 0;
		while (tab[i])
		{
			printf("%s--\n", tab[i]);
			t_tab[i] = ft_get_coord_tm(tab[i], 4, letter++);
			i++;
		}
		i = 0;
		/*while (*t_tab)
		{
			while (*t_tab)
			{
				printf("x:%d\ty:%d\n", (*t_tab)->x, (*t_tab)->y);
				*t_tab = (*t_tab)->next;
			}
			t_tab++;
			printf("---\n");
		}*/
		map = ft_solver(t_tab, map, 0, 2, 0);
		printf("%s--------\n", map);
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putstr_fd("error\n", 2);// USAGE A METTRE
	return (0);
}
