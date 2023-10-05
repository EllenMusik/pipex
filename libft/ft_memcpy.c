/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:22:36 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/10 15:18:47 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (!src && !dst && n != 0)
		return (0);
	while (x < n)
	{
		((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
		x++;
	}
	return (dst);
}

/*
int main(void)
{
	{char	str1[50] = "\0";
	char	str2[50] = "\0";
	char	ssrc1[50] = "\0";
	char	ssrc2[50] = "\0";

	ft_memcpy(((void *)0), ((void *)0), 3);
	printf("Ergebnis: %s\n", str1);
	memcpy(((void *)0), ((void *)0), 3);
	printf("Ergebnis: %s\n", str2);
	return (0);
}
*/
