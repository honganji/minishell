/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 15:36:18 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

/**
 * @brief deal with a pipe
 * 
 * The array type is t_exe. So the element has enum com and args divided with
 * space.
 * 
 * @param data data
 * @param arr hold elements that have enum command and args
 * @return void
 */
void	ft_pipe(t_data *data, t_exe *arr)
{
	char	*str;

	str = NULL;
	while ((*arr).str)
	{
		ft_exe_command(data, (*arr).str, (*arr).com);
		arr++;
	}
	str = ft_read_file(STDIN_FILENO);
	printf("%s", str);
	free(str);
}
