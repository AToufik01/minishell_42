/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:02:31 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/12 19:25:39 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_env	*ft_lst_env_last(t_lst_env *lst)
{
	t_lst_env	*cur;

	cur = lst;
	if (!lst)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_lst_env *ft_new_env(char *key,char *value)
{
	t_lst_env	*node;

	// node = malloc(sizeof(t_lst_env));
	node = gc_alloc(sizeof(t_lst_env), ALLOC_ENV);
	node->key = ft_strdup(key, ALLOC_ENV);
	node->value = ft_strdup(value, ALLOC_ENV);
	node->next = NULL;
	return node;
}

char	*ft_get_env_val(t_lst_env **lst_env, char	*key)
{
	t_lst_env	*cur;

	cur = ft_get_env(lst_env, key);
	if (cur == NULL)
		return NULL;
		// return ft_strdup("\t");
	return cur->value;
}

t_lst_env *ft_get_env(t_lst_env **lst_env, char	*key)
{
	t_lst_env	*cur;

	if (lst_env == NULL)
		return (NULL);
	cur = *lst_env;
	while (cur)
	{
		if (ft_strncmp(key, cur->key, ft_strlen(cur->key) + 1) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int ft_lst_add_back_env(t_lst_env **lst_env, t_lst_env *node_env)
{
    if (lst_env == NULL || ft_get_env(lst_env, node_env->key) != NULL)
		return (-1);
	if (*lst_env == NULL)
		*lst_env = node_env;
	else
		ft_lst_env_last(*lst_env)->next = node_env;
	return (0);
}

int	ft_lst_remove_env(t_lst_env **lst_env,char *key)
{
	t_lst_env *cur;
	t_lst_env *prev;

	if (lst_env == NULL)
		return -1;
	cur = *lst_env;
	if (ft_strncmp(cur->key, key, ft_strlen(cur->key) + 1) == 0)
	{
		*lst_env = cur->next;
		return (0);
	}
	while (cur)
	{
		if (ft_strncmp(cur->key, key, ft_strlen(cur->key) + 1) == 0)
		{
			prev->next = cur->next;
			return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	return -1;
}



int	index_of(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return i;
		i++;
	}
	return -1;
}

int	init_env(t_lst_env **lst, char **env)
{
	char	*value;
	int		i;
	int		len;

	i = 0;
	while (env[i])
	{
		len = index_of(env[i], '=');
		if (len == -1)
			return (-1);
		value = ft_strchr(env[i], '=') + 1;
		ft_lst_add_back_env(lst, ft_new_env(ft_substr(env[i], 0, len, ALLOC_ENV), value));
		i++;
	}
	return 1;
}

// int main(int argc, char const *argv[], char **env)
// {
// 	t_lst_env *lst;

// 	init_env(&lst, env);
// 	ft_get_env(&lst, "SHLVL")->value = ft_strdup("8");
	
// 	ft_lst_add_back_env(&lst, ft_new_env("pp", "TEST"));
// 	print_lst_env(lst);
// 	return 0;
// }
