/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:21:39 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 20:19:48 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief get the current definite directory path
 * 
 * @return void
 */
void	ft_pwd(t_data *data)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
	{
		data->exit_code = 1;
		syntax_err(NULL, "pwd: error retrieving current directory\n", NULL, 1);
	}
	cur_dir = ft_strjoin(cur_dir, "\n");
	ft_input_data(data, cur_dir, 0);
	free(cur_dir);
	data->exit_code = 0;
}
