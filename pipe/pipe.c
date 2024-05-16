/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/16 21:29:35 by ytoshihi         ###   ########.fr       */
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
 * @param lst hold elements that have enum command and args
 * @return void
 */
void	ft_pipe(t_data *data)
{
	char	*str;
	t_list	*lst;
	char	*file_name;

	str = NULL;
	lst = data->cmd_lst;
	while (lst)
	{
		file_name = ((t_cmd *)lst->content)->output.file_name;
		ft_exe_command(data, *(t_cmd *)lst->content);
		if (file_name)
		{
			str = ft_read_file(STDIN_FILENO);
			// ft_output_red(file_name, str, 0);
		}
		lst = lst->next;
	}
	str = ft_read_file(STDIN_FILENO);
	printf("result: %s", str);
	free(str);
}
