/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:42:46 by iostancu          #+#    #+#             */
/*   Updated: 2022/02/12 19:01:11 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *color, char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	if (!color)
		color = "\x1b[0m";
	while (*color)
		write(fd, color++, 1);
	while (*s)
		write (fd, s++, 1);
	write (fd, "\n", 1);
}

/*
void	ft_putendl_fd(char *color, char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*color)
		write(fd, color++, 1);
	while (*s)
		write (fd, s++, 1);
	color = "\x1b[0m";
	write (fd, "\n", 1);
}
*/
