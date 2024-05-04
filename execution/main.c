/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 23:26:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	main(void)
{
	t_data	*data;
	char	*arg;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	store_env(data);
	// test cd and pwd
	printf("----------------cd and pwd test----------------\n");
	ft_exe_command(data, NULL, PWD);
	printf("\n");
	ft_exe_command(data, "execution", CD);
	ft_exe_command(data, NULL, PWD);
	printf("\n");
	// test export, env, and unset
	printf("----------------export, env and unset test----------------\n");
	ft_exe_command(data, NULL, ENV);
	printf("\n");
	ft_exe_command(data, "GEN1=Nobunaga Oda", EXPORT);
	ft_exe_command(data, "GEN2=Hideyoshi Toyotomi", EXPORT);
	ft_exe_command(data, "GEN3=Ieyasu Tokugawa", EXPORT);
	ft_exe_command(data, NULL, ENV);
	printf("\n");
	ft_exe_command(data, "GEN3", UNSET);
	ft_exe_command(data, NULL, ENV);
	printf("\n");
	// test echo
	printf("----------------echo test----------------\n");
	ft_exe_command(data, "\"I am a hero\"", ECHO);
	// test $ usage and export update
	printf("----------------export update test----------------\n");
	arg = ft_rep_env(data, "$GEN1");
	ft_exe_command(data, arg, ECHO);
	free(arg);
	ft_exe_command(data, "GEN1=Kintama", EXPORT);
	arg = ft_rep_env(data, "$GEN1");
	ft_exe_command(data, arg, ECHO);
	free(arg);
	system("leaks minishell_exe");
	return (0);
}
