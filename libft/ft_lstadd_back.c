/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:51:34 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/04 16:35:43 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*adresse;

	adresse = ft_lstlast(*lst);
	if (adresse != NULL)
		adresse->next = new;
	if (adresse == NULL)
		*lst = new;
}
