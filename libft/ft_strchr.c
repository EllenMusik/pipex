/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:20:10 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/18 17:00:32 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return (0);
}

/*
int	main(void)
{
	const char	*s;
	int	c;

	s = "hallo\0";
	c = '\0';
	printf("mein Ergebnis: %s\n", ft_strchr(s, 't' + 256));
	printf("original Funktion; %s\n", strchr(s, 't' + 256));
	return (1);
}
*/
