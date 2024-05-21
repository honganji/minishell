/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:22:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 14:16:01 by ytoshihi         ###   ########.fr       */
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