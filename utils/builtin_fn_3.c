/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:45 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/19 22:26:50 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief input data for STDIN_FILENO
 * 
 * You can decide which format string or file.
 * @param str file path or string data
 * @param is_file flag if the data is string or is located in a file
 * @return void
*/
void	ft_input_data_from_file(t_data *data, char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		syntax_err(data, "Error opening file: ", str, 1);
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

/**
 * @brief put string into STDIN-fd
 * 
 * @param data whole data
 * @param str string to use as input
 * @return void
*/
void	ft_input_data_from_string(t_data *data, char *str)
{
	int		fds[2];

	if (pipe(fds))
	{
		syntax_err(data, "Pipe error: ", strerror(errno), 1);
		return ;
	}
	if (write(fds[1], str, ft_strlen(str)) == -1)
	{
		syntax_err(data, "Write error: ", strerror(errno), 1);
		close(fds[1]);
		return ;
	}
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
}

/**
 * @brief put string for file into STDIN-fd
 * 
 * @param data whole data
 * @param str string to use as input or file name
 * @param is_file flag if it is a file
 * @return void
*/
void	ft_input_data(t_data *data, char *str, int is_file)
{
	if (is_file)
		ft_input_data_from_file(data, str);
	else
		ft_input_data_from_string(data, str);
}
