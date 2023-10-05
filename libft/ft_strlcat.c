/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:17:18 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/10 13:49:19 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	x = ft_strlen(dst);
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize > x)
		dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

/*
int	main(void)
{
	char src1[] = " Append this :)";
	char dst1[] = "To this";
	char src2[] = " Append this :)";
	char dst2[] = "To this";
	int i =0, j = 0;
	while (src1[i]) i++;
	while (dst1[j]) j++;
	printf("The total length should be %d\n", i+j);
	i = ft_strlcat(dst1, src1, j);
	printf("%s\n", dst1);
	printf("return value(length): %d\n", i);
	j = 0;
	while (dst1[j] != '\0') j++;
	printf("The final length is %d\n\n", j);
	//i = strlcat(dst2, src2, i);
	strlcat(dst2, src2, 9);
	printf("%s\n", dst2);
	//printf("return value(length): %d\n", i);
	j = 0;
	while (dst1[j] != '\0') j++;
	printf("The final length is %d\n", j);
	return (0);
}
*/
