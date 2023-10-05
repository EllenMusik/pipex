/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:56:01 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/11 21:21:37 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			x;
	unsigned int	i;

	x = 0;
	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (src[x] && x + 1 < dstsize)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (i);
}

/*
int main(void)
{
	char string_test1[] = "This is ";
	unsigned int	i;
	unsigned int size;
	unsigned int	x;

	i = 0;
	while (string_test1[i] != '\0')
	{
		i++;
	}
	size = 10;
	if (size > i)
		size = i + 1;
	char dst[size];
	x = ft_strlcpy(dst, string_test1, size);
	printf("length is %d\n", i);
	printf("return value is %d\n", x);
	write(1, dst, size);
	write(1, "\n", 1);
	printf("Size of copied string is %d\n", size);
	write(1, "\n", 1);
	x = strlcpy(dst, string_test1, size);
	printf("length is %d\n", i);
	printf("return value is %d\n", x);
	write(1, dst, size);
	write(1, "\n", 1);
	printf("Size of copied string is %d\n", size);
}
*/
