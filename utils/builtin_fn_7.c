/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:21 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/02 10:36:16 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	ft_isstr_alpha(char *str)
{
	while (*str)
	{
		if (!ft_isalpha((int)*str++))
			return (0);
	}
	return (1);
}

void	setup_arg(t_exe	*params, char **args, t_data *data)
{
	params->status = 0;
	if (pipe(params->fds) == -1)
		critical_err(strerror(errno));
	params->tmp = args[0];
	args[0] = ft_strjoin("/", args[0]);
	args[0] = ft_check_exist(data, args[0]);
}
