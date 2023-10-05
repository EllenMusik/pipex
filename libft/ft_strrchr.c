/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:13:07 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/25 15:10:24 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (0);
}

/*
int	main(void)
{
	const char	*s;
	//int	c;
	s = "htallo\0";
	//c = '\0';
	printf("mein Ergebnis: %s\n", ft_strrchr(s, 'h'));
	printf("original Funktion; %s\n", strrchr(s, 'h'));
	return (0);
}
*/
