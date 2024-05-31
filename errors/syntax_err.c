/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/31 16:56:50 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"

void	set_exit_code(t_data *data, int code)
{
	data->exit_code = code;
}

void	syntax_err(t_data *data, char *str, char *cmd, int code)
{
	set_exit_code(data, code);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

void	token_syntax_err(t_data *data, char *str, int code)
{
	set_exit_code(data, code);
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}

int check_syntax(t_data *data, t_token *tokens)
{
    t_token *tmp;
    int first_in_lst;
    int first_in_cmd;

    first_in_lst = 1;
    first_in_cmd = 1;
    tmp = tokens;
    while (tmp != NULL)
	{
        // printf("Current token: %p, data: %s, type: %d\n", tmp, tmp->data, tmp->type);
        if (tmp->type == PIPE)
		{
            if (pipe_check(data, tmp, first_in_lst, first_in_cmd) == 1)
				return (1);
            first_in_cmd = 1;
        }
		else if (tmp->type == REDIR)
		{
            if (redir_check(data, tmp) == 1)
				return (1);
        }
        tmp = tmp->next;
        first_in_cmd = 0;
        first_in_lst = 0;
    }
    return (0);
}

int	pipe_check(t_data *data, t_token *tmp, int first_in_lst, int first_in_cmd)
{
	if (first_in_lst)
	{
		token_syntax_err(data, "|", 2);
		return (1);
	}
	else if (first_in_cmd && tmp->next == NULL)
	{
		token_syntax_err(data, "|", 2);
		return (1);
	}
	else if (tmp->next != NULL && tmp->next->type == PIPE)
	{
		token_syntax_err(data, "|", 2);
		return (1);
	}
	return(0);
}

int redir_check(t_data *data, t_token *tmp)
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
