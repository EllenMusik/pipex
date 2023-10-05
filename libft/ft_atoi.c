/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:59:17 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/19 21:15:55 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_convert(int x, int nbr, const char *str)
{
	int	res;

	res = 0;
	if (str[x] <= '9' && str[x] >= '0')
	{
		while (str[x] <= '9' && str[x] >= '0')
		{
			res *= 10;
			res += str[x] - '0';
			x++;
		}
		return (res * nbr);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int	x;
	int	nbr;

	nbr = 1;
	x = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n'
		|| str[x] == '\v' || str[x] == '\f' || str[x] == '\r')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			nbr *= -1;
		x++;
	}
	nbr = number_convert(x, nbr, str);
	return (nbr);
}

/*
int main(void)
{
	char *value = "694203";
	char *value1 = "+4582abc45";
	char *value2 = "-a1ascfd123";
	char *value3 = "";
	int number;
	number = ft_atoi(value);
	printf("this is the number: %d\n", number);
	number = atoi(value);
	printf("would atoi do: %d\n", number);
	number = ft_atoi(value1);
	printf("this is the number: %d\n", number);
	number = atoi(value1);
	printf("would atoi do: %d\n", number);
	number = ft_atoi(value2);
	printf("this is the number: %d\n", number);
	number = atoi(value2);
	printf("would atoi do: %d\n", number);
	number = ft_atoi(value3);
	printf("this is the number: %d\n", number);
	number = atoi(value3);
	printf("would atoi do: %d\n", number);
	return (0);
}
*/