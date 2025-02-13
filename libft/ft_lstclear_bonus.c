/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:26:11 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 13:49:39 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nlst;
	t_list	*plst;

	if (!lst || !del)
		return ;
	nlst = *lst;
	plst = *lst;
	while (nlst)
	{
		plst = plst->next;
		del(nlst->content);
		free(nlst);
		nlst = plst;
	}
	*lst = NULL;
}
