/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:19:29 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/04 09:13:24 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_del_current
** Deletes char passed in argument.
*/

static void		ft_del_current(char *map, char letter)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == letter)
			map[i] = '.';
		i++;
	}
}

/*
** ft_placement
** Fills the map with the tetrominos passed in argument. The first TM's piece is
** placed from the position 'pos'.
** The function returns zero if TM can't be placed.
*/

static int		ft_placement(t_point *tm, char *map, int pos, int size)
{
	int		i;

	while (tm)
	{
		i = pos + tm->x + (tm->y * (size + 1));
		if (!(map[i]) || map[i] != '.')
		{
			ft_del_current(map, tm->letter);
			return (0);
		}
		map[i] = tm->letter;
		tm = tm->next;
	}
	return (1);
}

/*
** ft_solver
** Recursive function using backtracking that tries to find the best solution
** with a map sized by 'size'.
** The function returns zero, if TMs can't be placed.
*/

static int		ft_solver(t_point **tm, char *map, int pos, int size, int i)
{
	if (!tm[i])
	{
		ft_putstr(map);
		return (1);
	}
	while (map[pos])
	{
		if (ft_placement(tm[i], map, pos, size) == 1)
		{
			if (ft_solver(tm, map, 0, size, i + 1) == 1)
				return (1);
		}
		pos++;
	}
	return (0);
}

/*
** *ft_run_solver
** Runs ft_solver until it finds the good size of the map.
*/

char			*ft_eventual_resizer(t_point **tm, char *map, int size)
{
	while (ft_solver(tm, map, 0, size, 0) == 0)
	{
		size++;
		map = ft_create_empty_map(size);
	}
	return (map);
}

/*
** ft_create_tm_struct_tab
** Splits file descriptor into array. Each part of array contains a TM.
** Checks TM's conformity
** For each TM : gets coordinates of each # and attributes a letter
** Puts each TM's structure into an array
** Runs the solver and display solution
*/

void			ft_run_solver(int fd, char letter, int size)
{
	int		i;
	char	*str;
	char	**tab;
	int		nb_tm;
	t_point	**t_tab;

	i = 0;
	str = ft_read_buff(fd);
	tab = ft_splittetris(str);
	nb_tm = ft_count_tm(str);
	if (ft_check_all(tab) == 0)
	{
		ft_putstr_fd("error\n", 2);
		return ;
	}
	if (!(t_tab = (t_point**)malloc(sizeof(**t_tab) * nb_tm + 1)))
		return ;
	t_tab[nb_tm] = 0;
	while (tab[i])
	{
		t_tab[i] = ft_get_coord_tm(tab[i], 4, letter);
		letter++;
		i++;
	}
	ft_eventual_resizer(t_tab, ft_create_empty_map(size), size);
}
