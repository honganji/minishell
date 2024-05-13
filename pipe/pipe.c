/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 17:51:26 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

void	ft_pipe(t_data *data, t_exe *arr)
{
	while ((*arr).str)
		ft_create_pipe(data, arr++);
	if (*(data->output))
		// TODO delete
		printf("%s\n", data->output);
}

void	ft_create_pipe(t_data *data, t_exe *arr)
{
	// pid_t		pid;

	// pid = fork();
	// if (pid == 0)
	// {
	// 	// TODO delete
	// 	printf("come here\n");
	// 	ft_exe_command(data, (*arr).str, (*arr).com);
	// 	exit(EXIT_SUCCESS);
	// }
	// // TODO delete
	// wait(NULL);
	// printf("parent process\n");
	// // TODO delete
	// printf("output: %s\n", data->output);
	ft_exe_command(data, (*arr).str, (*arr).com);
}
