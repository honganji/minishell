/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:56:48 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/23 12:31:52 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

void	set_sig(int sig)
{
	(void)sig;
	// g_sig = sig;
}

// change exit code depending on the last exit code
void	check_signal(t_data *data)
{
	(void)data;
	// if (g_sig && !data->exit_code)
	// 	data->exit_code = 1;
	// g_sig = 0;
}
