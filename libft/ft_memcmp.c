/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:29:06 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/11 20:34:48 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s1)[x] == ((unsigned char *)s2)[x])
		{
			x++;
		}
		else
		{
			return (((unsigned char *)s1)[x] - ((unsigned char *) s2)[x]);
		}
	}
	return (0);
}
