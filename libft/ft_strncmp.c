/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:59:42 by esteiner          #+#    #+#             */
/*   Updated: 2023/04/26 13:29:37 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while ((x < n && s1[x]) || (s2[x] && x < n))
	{
		if (s1[x] == s2[x])
		{
			x++;
		}
		else
		{
			return ((unsigned char)s1[x] - (unsigned char) s2[x]);
		}
	}
	return (0);
}

/*
int main(void)
{
	char *first = "Equal";
	char *second = "Equally";
	int decision;

	decision = ft_strncmp(first, second, 5);
	if (decision > 0)
		write(1, "First string is greater than second\n", 36);
	else 
	if (decision < 0)
		write(1, "Second string is greater than first\n", 36);
	else
		write(1, "They are equal\n", 15);
}
*/