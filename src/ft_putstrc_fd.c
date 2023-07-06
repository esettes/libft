/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:36:15 by iostancu          #+#    #+#             */
/*   Updated: 2022/02/12 19:01:15 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrc_fd(char *color, char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*color)
		write(fd, color++, 1);
	while (*s)
		write (fd, s++, 1);
	color = "\x1b[0m";
}
