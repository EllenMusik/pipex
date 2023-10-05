/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:52:56 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/08 17:45:47 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*adresse;
	t_list	*temporary;

	adresse = lst[0];
	if (lst[0] != 0)
	{
		while (adresse->next != 0)
		{
			del(adresse->content);
			temporary = adresse->next;
			free(adresse);
			adresse = temporary;
		}
		del(adresse->content);
		free(adresse);
		lst[0] = 0;
	}
}
