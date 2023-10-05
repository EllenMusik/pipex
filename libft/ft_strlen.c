/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:38:15 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/10 13:29:30 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

/*
int main(void)
{
	char *test = "hallo Welt";
	char *test1 = "";
	char *test2 = "Some th\0ing\0";

	printf("The first size: %lu\n", ft_strlen(test));
	printf("The second size: %lu\n", ft_strlen(test1));
	printf("The third size: %lu\n", ft_strlen(test2));
	printf("The first size: %lu\n", strlen(test));
	printf("The second size: %lu\n", strlen(test1));
	printf("The third size: %lu\n", strlen(test2));
	return (0);
}
*/