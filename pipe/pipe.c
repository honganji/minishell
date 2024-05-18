/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/18 16:42:44 by adprzyby         ###   ########.fr       */
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
void	handle_input_and_execute(t_data *data, t_cmd *cmd)
{
	t_redir	input;

	input = cmd->input;
	if (input.file_name)
	{
		if (input.is_single)
			ft_input_data(input.file_name, 1);
		else
			ft_input_data(input.file_name, 0);
	}
	ft_exe_command(data, *cmd);
}

void	handle_output(t_data *data, t_cmd *cmd, t_list *lst)
{
	char	*str;
	t_redir	output;

	output = cmd->output;
	if (output.file_name)
	{
		str = ft_read_file(STDIN_FILENO);
		if (!str)
			critical_err(strerror(errno));
		if (ft_output_red(output.file_name, str, output.is_single) == -1)
		{
			critical_err(strerror(errno));
			free(str);
		}
	}
	else if (!lst->next)
	{
		str = ft_read_file(STDIN_FILENO);
		if (!str)
			critical_err(strerror(errno));
	}
	if (lst && dup2(data->stdin_fd, STDIN_FILENO) == -1)
		critical_err(strerror(errno));
	free(str);
}

void	ft_pipe(t_data *data)
{
	t_list	*lst;

	lst = data->cmd_lst;
	while (lst)
	{
		handle_input_and_execute(data, (t_cmd *)lst->content);
		handle_output(data, (t_cmd *)lst->content, lst->next);
		lst = lst->next;
	}
}
