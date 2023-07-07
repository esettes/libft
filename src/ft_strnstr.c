/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:41:07 by iostancu          #+#    #+#             */
/*   Updated: 2022/02/19 16:59:06 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	b = (char *)big;
	if (*little == '\0')
		return (b);
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (b[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
