/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 20:01:39 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

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
