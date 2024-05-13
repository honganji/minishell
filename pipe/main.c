/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 17:52:19 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

int	main(int argc, char **argv, char **env)
{
	t_exe	*arr;
	t_data	*data;
	int		i;
	// t_com	*arr_com;
	// char	**arr_str;

	(void)argc;
	(void)argv;
	i = 0;
	arr = ft_calloc(4, sizeof(t_exe));
	// arr_com = ft_calloc(3, sizeof(t_com));
	// arr_str = ft_calloc(3, sizeof(char *));
	// arr_com = (t_com *){ECHO, CD, ETC};
	// arr_str = (char **){"king", "execution", "/ls"};
	// while (i < 3)
	// {
	// 	arr[i]->com = arr_com[i];
	// 	arr[i]->str = arr_str[i];
	// 	i++;
	// }
	arr[0].com = ECHO;
	arr[0].str = ".";
	arr[1].com = ETC;
	arr[1].str = "/ls";
	arr[2].com = ETC;
	arr[2].str = "WOW";
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	ft_store_env(data, env);
	ft_pipe(data, arr);
	// system("leaks minishell_pipe");
	return (0);
}
