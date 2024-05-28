/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 13:40:25 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

/**
 * @brief check if there is input and if there is, use it
 * 
 * @param data data
 * @param cmd_lst linked list hold elements that have info about each command
 * @return void
 */
static void	check_input(t_data *data, t_list *cmd_lst)
{
	t_redir	input;

	input = ((t_cmd *)cmd_lst->content)->input;
	if (input.file_name)
	{
		if (input.is_single)
			ft_input_data(data, input.file_name, 1);
		else
			input_heredoc(data, input.file_name);
	}
}

/**
 * @brief check if there is output and if there is, use it
 * 
 * @param data data
 * @param cmd_lst linked list hold elements that have info about each command
 * @return void
 */
static void	check_output(t_list *cmd_lst)
{
	t_redir	output;
	char	*str;

	output = ((t_cmd *)cmd_lst->content)->output;
	if (output.file_name)
	{
		str = ft_read_file(STDIN_FILENO);
		ft_output_red(output.file_name, str, output.is_single);
		free(str);
	}
	else if (!cmd_lst->next)
	{
		str = ft_read_file(STDIN_FILENO);
		printf("%s", str);
		free(str);
	}
}

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
	t_list	*cmd_lst;

	str = NULL;
	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		check_input(data, cmd_lst);
		ft_exe_command(data, *(t_cmd *)cmd_lst->content);
		check_output(cmd_lst);
		cmd_lst = cmd_lst->next;
	}
	free(str);
}
