/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 21:24:26 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

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
	t_exe	*arr;
	t_data	*data;

	(void)argc;
	(void)argv;
	arr = NULL;
	data = (t_data *)ft_calloc(1, sizeof(t_data));

	// Set the valuables
	set_val(data, &arr, env);

	// command test
	command_test(data);

	// pipe test
	pipe_test(data, arr);

	// redirection test
	red_test(data);

	clear_lst(data->env_lst);
	free(data);
	// system("leaks minishell");
	return (0);
}
