/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:21 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/06 18:21:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	ft_isstr_alpha(char *str)
{
	while (*str)
	{
		if (!ft_isalpha((int)*str++))
			return (0);
	}
	return (1);
}

void	setup_arg(t_exe	*params, char **args, t_data *data)
{
	params->status = 0;
	if (pipe(params->fds) == -1)
		critical_err(strerror(errno));
	params->tmp = args[0];
	args[0] = ft_strjoin("/", args[0]);
	args[0] = ft_check_exist(data, args[0]);
	if (!access(params->tmp, X_OK))
		args[0] = ft_free_strjoin(args[0], params->tmp);
}

int	redir_check(t_data *data, t_token *tmp)
{
	if (tmp->next == NULL)
	{
		token_syntax_err(data, "newline", 2);
		return (1);
	}
	else if (tmp->next->type == PIPE)
	{
		token_syntax_err(data, "|", 2);
		return (1);
	}
	else if (tmp->next->type != WORD && tmp->next->type != REDIR)
	{
		token_syntax_err(data, "newline", 2);
		return (1);
	}
	else if (tmp->next->type == REDIR)
	{
		token_syntax_err(data, tmp->next->data, 2);
		return (1);
	}
	return (0);
}
