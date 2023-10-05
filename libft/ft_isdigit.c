/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:42:23 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/09 14:16:46 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	int i;

	i = -1;
	printf("%i", isdigit(304));
	printf("%i", ft_isdigit(304));
	while (i < 530)
	{
		if (!!ft_isdigit(i) != !!isdigit(i))
		{
			printf("TEST_FAILED %i", i);
			exit(0);
		}
		i++;
	}
	printf("TEST_SUCCESS");
	return(0);
}
*/
