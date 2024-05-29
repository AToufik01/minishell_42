/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:38:56 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/29 11:25:10 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_arg(char *str)
{
	int	i;

	i = 1;
	if (str == NULL || str[0] != '-' || str[1] != 'n')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

void	print_echo(char **str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			ft_putstr_fd(str[i], 1);
		i++;
		if (i < len && str[i - 1])
			ft_putstr_fd(" ", 1);
	}
}

int	ft_echo(t_cmd *cmd)
{
	char	**cmd_str;
	int		i;

	i = 0;
	cmd_str = cmd->cmd + 1;
	while (ft_is_arg(cmd_str[i]))
		i++;
	print_echo(cmd_str + i, cmd->len);
	if (i == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
