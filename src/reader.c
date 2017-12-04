/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:13:40 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/04 09:13:54 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_read_buff
** Reads and returns the string from the file descriptor.
*/

char	*ft_read_buff(int fd)
{
	int		len;
	int		ret;
	char	*buff;
	char	*newbuff;
	char	tmp[BUFF_SIZE + 1];

	len = 0;
	buff = malloc(1);
	buff[0] = 0;
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		len = len + ret;
		if (!(newbuff = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strcpy(newbuff, buff);
		ft_strcat(newbuff, tmp);
		//free(buff);
		buff = newbuff;
		buff[len] = '\0';
	}
	if (ret == -1)
		write(2, "error read()", 13);
	return (buff);
}
