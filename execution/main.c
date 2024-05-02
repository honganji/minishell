/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 00:03:53 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	main(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->args = create_args("2", "ls", "-a");
	ft_exe_command(data);
	free_data(data);
	data->args = create_args("2", "cat", ".gitignore");
	ft_exe_command(data);
	free_data(data);
	data->args = create_args("3", "echo", "-n", "42 Heilbronn\n");
	ft_exe_command(data);
	free_data(data);
	free(data);
	// system("leaks minishell_exe");
	return (0);
}
