/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/30 18:20:21 by adprzyby         ###   ########.fr       */
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

int	check_syntax(t_data *data, t_token **current_token, int *is_first)
{
	t_token *tmp;
	int	first_in_lst;

	first_in_lst = 1;
	tmp = (*current_token);
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
		{
			if (first_in_lst || (*is_first && (tmp->next == NULL || tmp->next->type == PIPE)))
			{
				token_syntax_err(data, "|", 2);
				return (1);
			}
			*is_first = 1;
		}
		else if (tmp->type == REDIR)
		{
			if (tmp->next == NULL)
			{
				token_syntax_err(data, "newline", 2);
				return (1);
			}
		}
		tmp = tmp->next;
		*is_first = 0;
	}
	return (0);
}
