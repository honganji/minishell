/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:22:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 16:46:47 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief Accept input until you face EOF
 *
 * @param data data
 * @param eof end of file
 * @return void
 * 
 */
void    input_heredoc(t_data *data, char *eof)
{
	char	*str;
	char	*tmp;

	str = readline("> ");
	while (!ft_strnstr(str, eof, ft_strlen(str)))
	{
		printf("> ");
        rl_redisplay();
		tmp = readline("");
		str = ft_free_strjoin(str, tmp);
		str = ft_free_strjoin(str, "\n");
	}
	ft_input_data(data, str, 0);
}

/**
 * @brief Replace into an env variable
 *
 * @param data data
 * @param str string of token
 * @return char *
 * 
 */
char	*replace_env(t_data *data, char *str)
{
	char	*arg;

	if (!ft_strchr(str, '$'))
		return (str);
	if (!ft_strncmp("$?", str, ft_strlen("$?")))
		return (ft_strdup(ft_itoa(data->exit_code)));
	arg = ft_rep_env(data, str);
	if (!ft_strncmp(arg, str, ft_strlen(str)))
		return (NULL);
	return (arg);
}

/**
 * @brief Replace into an env variable
 *
 * @param data data
 * @param str string of token
 * @return char *
 * 
 */
void	remove_quote(char **str, int *is_skip)
{
	if (!(*str))
		return ;
	if (ft_strchr(*str, '\''))
		*is_skip = 1;
	if (*(*str) == '\'')
		*str = ft_strtrim(*str, "\'");
	else
		*str = ft_strtrim(*str, "\"");
}

/**
 * @brief Store exit code
 *
 * @param data data
 * @param status the status to get exit code
 * @param fds two file descriptors for a pipe
 * @param pid process id
 * @return void
 * 
 */
void	store_ec(t_data *data, int status, int fds[2], pid_t pid)
{
	close(fds[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		data->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data->exit_code = 128 + WTERMSIG(status);
}

/**
 * @brief Replace into an env variable
 *
 * @param data data
 * @param str string of token
 * @return char *
 * 
 */
void	exe_builtin(int fds[2], char **args)
{
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	if (execve(args[0], args, NULL) == -1)
		exit(EXIT_FAILURE);
}
