/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:31:45 by oozkaya           #+#    #+#             */
/*   Updated: 2017/11/29 13:58:23 by ade-verd         ###   ########.fr       */
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

char	*ft_read_buff(int fd);
char	**ft_splittetris(char *str);
int		ft_check_all(char **tab);

#endif
