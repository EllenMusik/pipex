/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:33:18 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/17 17:21:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nbrconvert(char *nbr, int n, int sign, int length)
{
	if (n == 0 && length >= sign)
	{
		nbr[0] = '0';
		return (nbr);
	}
	if (n < 0)
	{
		nbr[0] = '-';
		sign++;
		n = n * -1;
	}
	if (length >= sign)
	{
		nbr[length] = n % 10 + '0';
		length--;
		nbrconvert(nbr, n / 10, sign, length);
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		m;

	m = n;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (m < 0)
	{
		i++;
		m = m * -1;
	}
	while (m > 9)
	{
		m = m / 10;
		i++;
	}
	nbr = malloc(sizeof(char) * (i + 2));
	if (!nbr)
		return (0);
	nbr = nbrconvert(nbr, n, 0, i);
	nbr[i + 1] = 0;
	return (nbr);
}

/*
int	main(void)
{
	printf("number: %s\n", ft_itoa(-1234));
	return (0);
}
*/
