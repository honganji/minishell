/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:31:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 16:54:52 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_exit(int code, t_data *data)
{
	(void)data;
	// free_env_lst(data);
	// free_cmd_lst(data);
	// free(data);
	system("leaks minishell");
	exit(code);
}
