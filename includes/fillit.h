/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:31:45 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/04 09:02:59 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1

typedef struct	s_point
{
	int			x;
	int			y;
	char		letter;
	void		*next;
}				t_point;

char			*ft_read_buff(int fd);
char			**ft_splittetris(char *str);
int				ft_count_tm(char const *str);
int				ft_check_all(char **tab);
char			*ft_create_empty_map(int side);
t_point			*ft_get_coord_tm(char *src, int size, char letter);
char			*ft_eventual_resizer(t_point **tm, char *map, int size);
void			ft_run_solver(int fd, char letter, int size);

#endif
