/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:56:48 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/19 22:06:46 by ytoshihi         ###   ########.fr       */
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
	g_sig = sig;
}

// change exit code depending on the last exit code
void	check_signal(t_data *data)
{
	if (g_sig)
		data->exit_code = 1;
	// TODO delete
	printf("exit code: %d\n", data->exit_code);
	g_sig = 0;
}
