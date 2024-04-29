#include "../minishell.h"

void print_lst_export(t_lst_env *lst)
{
	t_lst_env *cur;
	cur = lst;
	while (cur)
	{
		printf("declare -x ");
		printf("%s", cur->key);
		printf("=\"%s\"\n", cur->value);
		cur = cur->next;
	}
}

int	ft_strcmp(char *s1,char *s2)
{
	int i;
	i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
void	print_lst_order_alpha(t_lst_env **lst)
{
	t_lst_env	*cur;

	cur = *lst;
	while(cur->next!= NULL)
	{
		if (ft_strcmp(cur->key,cur->next->key) > 0)
		{
		  	char *temp = cur->key;
		  	char *temp1 = cur->value;
            cur->key = cur->next->key;
			cur->value = cur->next->value;
            cur->next->key = temp;
            cur->next->value = temp1;
			cur= *lst;
		}
		else
			cur = cur->next;
	}
	cur = *lst;
	print_lst_export(cur);
}

int	index_key(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' && str[i + 1] == c) || str[i] == '=')
			return i;
		i++;
	}
	return -1;
}
int ft_check_lst_key(t_lst_env *lst,char *key)
{
	t_lst_env	*cur;

	cur = lst;
	while (cur)
	{
		if (ft_strncmp(cur->key,key,ft_strlen(cur->key))==0)
			return(1);
		cur = cur->next;
	}
	return (0);
}
void	ft_change_val(t_lst_env *lst ,char *key,char *value)
{
	t_lst_env	*cur;
	cur = lst;
	while (cur)
	{
		if (ft_strncmp(cur->key,key,ft_strlen(cur->key))==0)
		{
			cur->value = value;
			break;
		}
		cur = cur->next;
	}
}
void	ft_add_val(t_lst_env	*lst,char *key ,char *val)
{
	t_lst_env	*cur;
	cur = lst;
	while (cur)
	{
		if (ft_strncmp(cur->key,key,ft_strlen(cur->key))==0)
		{
			cur->value = ft_strjoin(cur->value, val);
			break;
		}
		cur = cur->next;
	}
}
int	ft_export(t_lst_env *lst_env, t_cmd *str)
{
	int		len;
	char	*value;
	char	*key;
	int i;
	i = 1;

	if (str->cmd[i]== NULL)
		print_lst_order_alpha(&lst_env);
	else
	{
		while (str->cmd[i])
		{
			len = index_key(str->cmd[i], '=');
			if (len == -1)
				return -1;
			value = ft_strchr(str->cmd[i], '=') + 1;
			key = ft_substr(str->cmd[i], 0, len);
			if (str->cmd[i][len - 1]=='-')
			{
				printf("export: `%s': not a valid identifier\n",str->cmd[i]);
				i++;
				continue;
			}
			if (ft_check_lst_key(lst_env,key) == 1)
			{
				if (str->cmd[i][len]=='+')
					ft_add_val(lst_env,key,value);
				else
					ft_change_val(lst_env,key,value);
			}
			else
				ft_lst_add_back_env(&lst_env, ft_new_env(key, value));
			i++;
		}
	}
	return (1);
}
