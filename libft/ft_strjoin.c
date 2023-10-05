/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:26:03 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/12 11:55:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	i = ft_strlen(s1) + 1;
	k = ft_strlen(s2) + 1;
	s3 = malloc(sizeof(char) * (i + k));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, i);
	ft_strlcat(s3, s2, i + k);
	return (s3);
}

/*
int	main(void)
{
	printf("test: %s\n", ft_strjoin("hallo, ", "ich bin Ellen!"));
	return (0);
}
*/