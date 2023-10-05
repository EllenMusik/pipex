/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:11:48 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/09 14:14:06 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	char string_test1 = 'Z';
	int result;
	result = is_alnum(string_test1);
	printf("mein is alnum: %d\n", result);
	result = isalnum(string_test1);
	printf("isalnum: %d\n", result);
	return (0);
}
*/