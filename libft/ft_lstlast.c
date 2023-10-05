/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellensteiner <ellensteiner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:22:03 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/26 02:44:10 by ellensteine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*adresse;

	printf(".\n");
	if (lst == NULL)
		return (NULL);
	adresse = lst;
	while (adresse->next != NULL)
	{
		printf("interate item: %i\n", *(int *)adresse->content);
		adresse = adresse->next;
	}
	return (adresse);
}
