/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:00:48 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/18 19:19:40 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*adresse;

	c = 0;
	adresse = lst;
	if (lst != NULL)
		c++;
	else
		return (0);
	while (adresse->next != NULL)
	{
		adresse = adresse->next;
		c++;
	}
	return (c);
}
