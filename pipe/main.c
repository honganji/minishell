/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:08:22 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

int	main(int argc, char **argv, char **env)
{
	t_exe	*arr;
	t_data	*data;
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
	arr = ft_calloc(4, sizeof(t_exe));
	arr[0].com = ECHO;
	arr[0].str = ".";
	arr[1].com = ETC;
	arr[1].str = "/ls -a";
	arr[2].com = ECHO;
	arr[2].str = "WOW";
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	ft_input_data("", 0);
	ft_store_env(data, env);
	ft_pipe(data, arr);
	// system("leaks minishell_pipe");
	return (0);
}
