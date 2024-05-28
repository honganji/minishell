/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:31:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 18:51:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_exit(t_data *data, int is_cmd, char *arg, char **arr)
{
	unsigned char	code;
	char			*str;

	if (ft_isstr_alpha(arg))
	{
		str = ft_strjoin(arg, ": numeric argument required");
		syntax_err(data, str, "exit", 0);
		free(str);
		code = 255;
	}
	else if (arr_len(arr) > 2)
	{
		str = ft_strjoin(arg, ": too many arguments");
		syntax_err(data, str, "exit", 0);
		free(str);
		code = 1;
	}
	else if (arg)
		code = (unsigned char)ft_atoi(arg);
	else
		code = 0;
	if (is_cmd)
		free_cmd_lst(data);
	free_env_lst(data);
	free(data);
	exit(code);
}
