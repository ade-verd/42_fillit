/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:31:45 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/30 12:59:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# include <stdio.h> //A SUPPRIMER

# define BUFF_SIZE 1

typedef struct	s_point
{
	int			x;
	int			y;
	void		*next;
}				t_point;


char			*ft_read_buff(int fd);
char			**ft_splittetris(char *str);
int				ft_check_all(char **tab);
char			*ft_create_empty_map(int side);
char			*ft_resize_map(char *str);

#endif
