/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/29 12:16:02 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	what_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (PIPE);
		else if (str[i] == '>' || str[i] == '<')
			return (is_redir(str, i));
		else
			return (WORD);
		i++;
	}
	return (0);
}

int	is_redir(char *str, int i)
{
	if (str[i] == '>' && (str[i + 1] == '\0' || str[i + 1] != '>'))
		return (REDIR);
	else if (str[i] == '<' && (str[i + 1] == '\0' || str[i + 1] != '<'))
		return (REDIR);
	else if (str[i] == '>' && (str[i + 1] == '>' && (str[i + 2] == '\0' || str[i + 2] != '>')))
		return (REDIR);
	else if (str[i] == '<' && (str[i + 1] == '<' && (str[i + 2] == '\0' || str[i + 2] != '<')))
		return (REDIR);
	else
		return (WORD);
}

t_token	*tokenization(char **tokens)
{
	t_token	*token;
	t_token	*tmp;
	int		i;

	i = 0;
	token = token_init();
	tmp = token;
	while (tokens[i])
	{
		tmp->data = tokens[i];
		tmp->type = what_token(tmp->data);
		if (!tokens[i + 1])
		{
			tmp->next = NULL;
			break ;
		}
		tmp->next = token_init();
		tmp->id = i;
		tmp = tmp->next;
		i++;
	}
	return (token);
}
