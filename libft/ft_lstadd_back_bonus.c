/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:44:16 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/08 18:16:16 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (!lst)
		return ;
	lstlast = *lst;
	if (!lstlast)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
