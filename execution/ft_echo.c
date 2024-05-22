/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:54 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 14:21:19 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief read the input and send it to STDIN
 * 
 * @param args arguments
 * @return void
 */
void	ft_echo(char **args, t_data *data)
{
	int		i;
	char	*str;

	i = 1;
	data->exit_code = 0;
	if (!args[1])
	{
		ft_input_data(data, "\n", 0);
		return ;
	}
	if (ft_strncmp(args[1], "-n", ft_strlen(args[1])))
	{
		str = ft_join_with_space(&args[i]);
		str = ft_free_strjoin(str, "\n");
	}
	else
		str = ft_join_with_space(&args[++i]);
	ft_input_data(data, str, 0);
}
