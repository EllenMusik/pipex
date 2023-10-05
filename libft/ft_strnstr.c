/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:41:05 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/11 20:14:58 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	z;

	z = 0;
	y = 0;
	x = 0;
	if (needle[x] == 0)
		return (&((char *)haystack)[0]);
	while (haystack[z] && z < len)
	{
		x = z;
		while (haystack[x] == needle[y] && x < len)
		{
			if (needle[y + 1] == '\0')
				return (&((char *)haystack)[x - y]);
			x++;
			y++;
		}
		z++;
		y = 0;
	}
	return (0);
}

/*
int main(void)
{
  char *haystack = "aaabcabcd";
  //char *needle = "orem";
  
  printf("%s\n", ft_strnstr(haystack, "aabc", 20));
  printf("%s\n", strnstr(haystack, "aabc", 20)); 
  return(0);
}
*/