/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/05 10:51:45 by adprzyby         ###   ########.fr       */
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
	if (str[i] == '>' && str[i + 1] != '\0' && str[i + 1] == '>')
		return (REDIR);
	else if (str[i] == '<' && str[i + 1] != '\0' && str[i + 1] == '<')
		return (REDIR);
	else if (str[i] == '>')
		return (REDIR);
	else if (str[i] == '<')
		return (REDIR);
	else
		return (WORD);
	return (0);
}

t_token	*create_and_link_token(t_token *tmp, t_token **token,
		t_token **last_token, char *data)
{
	t_token	*new_token;

	new_token = split_combined_tokens(tmp);
	if (new_token != tmp)
	{
		if (tmp == *token)
			*token = new_token;
		else if (*last_token != NULL)
			(*last_token)->next = new_token;
		*last_token = new_token;
		tmp = new_token->next;
	}
	else
		*last_token = tmp;
	tmp->type = what_token(data);
	return (tmp);
}

t_token	*tokenization(char **tokens)
{
	t_token	*token;
	t_token	*tmp;
	t_token	*last_token;
	int		i;

	token = token_init();
	tmp = token;
	last_token = NULL;
	i = 0;
	while (tokens[i])
	{
		tmp->data = ft_strdup(tokens[i]);
		tmp = create_and_link_token(tmp, &token, &last_token, tmp->data);
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
