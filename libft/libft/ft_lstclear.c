/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:18:38 by jriga             #+#    #+#             */
/*   Updated: 2025/04/29 15:49:15 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		if (start->type == TYPE_PTR && del)
			del(start->u.content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
