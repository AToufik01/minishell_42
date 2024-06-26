/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:43:35 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/30 00:16:23 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t__lst_token	*ft_get_next_token(t__lst_token *node)
{
	t__lst_token	*cur;

	cur = node;
	while (cur)
	{
		if (cur->type == WSP)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t__lst_token	*ft_new_token(char *str, t_type type)
{
	t__lst_token	*token;

	if (str == NULL)
		return (NULL);
	token = gc_alloc(sizeof(t__lst_token), ALLOC);
	token->str = str;
	token->type = type;
	token->next = NULL;
	return (token);
}

t__lst_token	*ft__lst_token_last(t__lst_token **lst)
{
	t__lst_token	*cur;

	cur = *lst;
	if (!lst)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ft_lst_token_add_back(t__lst_token **lst, t__lst_token *token)
{
	if (lst == NULL || token == NULL)
		return ;
	if (*lst == NULL)
		*lst = token;
	else
		ft__lst_token_last(lst)->next = token;
}

void	print__lst_tokens(t__lst_token *lst)
{
	while (lst)
	{
		printf("(%s)\t", lst->str);
		if (lst->type == WORD)
			printf("WORD\n");
		else if (lst->type == WSP)
			printf("WSP\n");
		else if (lst->type == APPEND)
			printf("APPEND\n");
		else if (lst->type == HEARDOC)
			printf("HEARDOC\n");
		else if (lst->type == INPUT)
			printf("INPUT\n");
		else if (lst->type == OUTPUT)
			printf("OUTPUT\n");
		else if (lst->type == VAR)
			printf("VAR\n");
		else if (lst->type == PIPE)
			printf("PIPE\n");
		else if (lst->type == DOUB_Q || lst->type == SING_Q)
			printf("DOUB_Q\n");
		else if (lst->type == EXIT_STATUS)
			printf("EXIT_STATUS\n");
		lst = lst->next;
	}
}
