/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:08 by emagueri          #+#    #+#             */
/*   Updated: 2024/05/29 21:56:01 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while ((s1[i] && s2[i] && i < n)
		&& ((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
