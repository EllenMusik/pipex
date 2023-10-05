/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:59:36 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/10 19:58:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (n == 0)
		return (0);
	return (0);
}

/*
int main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("test 1: %d\n", ft_memchr(s, 0, 0));
	printf(".test 1: %d\n", memchr(s, 0, 0));
	printf("test 2: %d\n", ft_memchr(s, 2, 3) == s + 2);
	printf(".test 2: %d\n", memchr(s, 2, 3) == s + 2);
	printf("test 3: %d\n", (ft_memchr(s, 2 + 256, 3) == s + 2));
	printf(".test 3: %d\n", (memchr(s, 2 + 256, 3) == s + 2));
	return (0);
}
*/