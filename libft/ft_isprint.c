/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:43:09 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/09 14:12:43 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c < 127)
		return (1);
	else
		return (0);
}

/*
int main()
{
   int c;
   for(c = 1; c <= 127; ++c)
   {
   		if (isprint(c)!= 0)
             printf("%c ", c);
		if (is_print(c)!= 0)
             printf("%c\n", c);
   }
   return (0);
}
*/
