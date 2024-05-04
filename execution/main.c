/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 09:29:05 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	clear_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	store_env(&data);
	// ft_exe_command(data, "-n,\"I am a hero\"\n", ECHO);
	// ft_exe_command(data, "pwd", PWD);
	// printf("\n");
	// ft_exe_command(data, "execution", CD);
	ft_exe_command(data, "KING=king", EXPORT);
	ft_exe_command(data, "env", ENV);
	printf("\n");
	ft_exe_command(data, "KING", UNSET);
	ft_exe_command(data, "env", ENV);
	// free(data->arr);
	clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell_exe");
	return (0);
}
