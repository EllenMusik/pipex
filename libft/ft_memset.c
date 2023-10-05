/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:21:23 by esteiner          #+#    #+#             */
/*   Updated: 2022/12/19 18:08:06 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)str)[x] = (unsigned char)c;
		x++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[50] = "hallo Welt";
	char	str2[50] = "hallo Welt";

	ft_memset(str1, 'g', 4);
	printf("Ergebnis: %s\n", str1);
	memset(str2, 'g', 4);
	printf("Ergebnis: %s\n", str2);
	return (0);
}
*/
