/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:31:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/25 10:14:55 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_exit(int code, t_data *data, int is_cmd)
{
	if (is_cmd)
		free_env_lst(data);
	free_cmd_lst(data);
	free(data);
	// system("leaks minishell");
	exit(code);
}
