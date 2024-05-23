/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:22:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 13:42:10 by adprzyby         ###   ########.fr       */
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

char 	*join_to_env(char *str, t_list *env_list)
{
	while (env_list)
	{
		str = ft_free_strjoin(str, (*(t_env *)(env_list->content)).key);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "=");
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, (*(t_env *)(env_list->content)).value);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "\n");
		if (!str)
			critical_err(strerror(errno));
		env_list = env_list->next;
	}
	return (str);
}
