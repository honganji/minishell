/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/11 13:24:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	clear_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		free(((t_env *)tmp->content)->key);
		free(((t_env *)tmp->content)->value);
		free(tmp->content);
		lst = lst->next;
		free(tmp);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int		i;

	// env = ft_split("", ' ');
	(void)argc;
	(void)argv;
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	i = 0;
	ft_store_env(data, env);
	printf("----------------pwd test-----------------------\n");
	ft_exe_command(data, NULL, PWD);
	ft_read_stdin();
	printf("\n----------------cd test------------------------\n");
	ft_exe_command(data, "execution", CD);
	ft_exe_command(data, NULL, PWD);
	ft_read_stdin();
	printf("\n");
	printf("----------------env test-----------------------\n");
	ft_exe_command(data, NULL, ENV);
	ft_read_stdin();
	printf("----------------export, and unset test---------\n");
	ft_exe_command(data, "General $GEN1", ECHO);
	ft_read_stdin();
	ft_exe_command(data, "GEN1=Nobunaga Oda", EXPORT);
	ft_exe_command(data, "General $GEN1", ECHO);
	ft_read_stdin();
	ft_exe_command(data, "GEN2=Hideyoshi Toyotomi", EXPORT);
	ft_exe_command(data, "GEN3=Ieyasu Tokugawa", EXPORT);
	ft_exe_command(data, "GEN1", UNSET);
	ft_exe_command(data, "General $GEN1", ECHO);
	ft_read_stdin();
	printf("\n");
	printf("----------------echo test---------------------\n");
	ft_exe_command(data, "\"I am a hero\"", ECHO);
	ft_read_stdin();
	printf("----------------export update test------------\n");
	ft_exe_command(data, "General $GEN2", ECHO);
	ft_read_stdin();
	ft_exe_command(data, "GEN2=Kintama", EXPORT);
	ft_exe_command(data, "General $GEN2", ECHO);
	ft_read_stdin();
	printf("----------------builtin command test----------\n");
	ft_exe_command(data, "/ls -l", ETC);
	printf("\n-----Finish-----------------------------------\n");
	clear_lst(data->env_lst);
	free(data);
	system("leaks minishell_exe");
	return (0);
}
