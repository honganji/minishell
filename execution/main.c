/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 15:13:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	main(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	ft_exe_command(data, "-n,\"I am a hero\"\n", ECHO);
	ft_exe_command(data, "pwd", PWD);
	printf("\n");
	ft_exe_command(data, "execution", CD);
	ft_exe_command(data, "env", ENV);
	// system("leaks minishell_exe");
	return (0);
}
