/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 11:13:06 by ytoshihi         ###   ########.fr       */
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
	t_redir	output;
	t_redir	input;

	str = NULL;
	lst = data->cmd_lst;
	while (lst)
	{
		output = ((t_cmd *)lst->content)->output;
		input = ((t_cmd *)lst->content)->input;
		if (input.file_name)
		{
			if (input.is_single)
				ft_input_data(data, input.file_name, 1);
			else
				ft_input_data(data, input.file_name, 0);
		}
		ft_exe_command(data, *(t_cmd *)lst->content);
		if (output.file_name)
		{
			str = ft_read_file(STDIN_FILENO);
			ft_output_red(output.file_name, str, output.is_single);
		}
		else if (!lst->next)
		{
			str = ft_read_file(STDIN_FILENO);
			printf("%s", str);
		}
		lst = lst->next;
	}
	free(str);
	set_sig(0);
}
