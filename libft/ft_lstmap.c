/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:07:05 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/19 20:43:06 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*firstnode;
	t_list	*adresse;

	firstnode = 0;
	adresse = lst;
	if ((*f) == 0 || (*del) == 0)
		return (0);
	while (lst != 0)
	{
		adresse = ft_lstnew((*f)(lst->content));
		if (!adresse)
		{
			if (adresse != 0)
				ft_lstclear(&firstnode, del);
			return (0);
		}
		ft_lstadd_back(&firstnode, adresse);
		lst = lst->next;
	}
	return (firstnode);
}
