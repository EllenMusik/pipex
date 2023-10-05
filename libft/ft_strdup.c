/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:00:31 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/11 21:20:51 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*s2;

	x = ft_strlen(s1) + 1;
	s2 = malloc(x * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, x);
	return (s2);
}
