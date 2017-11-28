/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:20:09 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/22 12:32:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static void		ft_putchar_fd(char c, int fd)
{
	int		ret;

	if (fd <= 0)
	{
		write(2, "error: bad file descriptor", 13);
		return ;
	}
	if ((ret = write(fd, &c, 1)) < 0)
		write(2, "write() error", 13);
}

void			ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
