/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:40:49 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/04 22:05:05 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*newnode;
	t_list	*head;
	void	*newcontent;

	head = NULL;
	newnode = NULL;
	cur = lst;
	while (cur)
	{
		newcontent = f(cur->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_bSPACEk(&head, newnode);
		cur = cur->next;
	}
	return (head);
}
