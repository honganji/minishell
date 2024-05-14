/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/14 16:33:24 by ytoshihi         ###   ########.fr       */
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
			return (what_redir(str, i));
		else
			return (WORD);
		i++;
	}
	return (0);
}
// The what_token function takes a string as input and determines the type of token based on its content.

int what_redir(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] != '\0' && str[i + 1] == '>')
		return (REDIR_APP_OUT);
	else if (str[i] == '<' && str[i + 1] != '\0' && str[i + 1] == '<')
		return (REDIR_HERE);
	else if (str[i] == '>')
		return (REDIR_OUT);
	else if (str[i] == '<')
		return (REDIR_IN);
	return (0);
}
// what_redir returns the type of redirection token

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
		tmp->next = token_init();
		tmp->id = i;
		tmp = tmp->next;
		i++;
	}
	tmp = token;
	while (tmp && tmp->data)
	{
		printf("Token: %s\n", tmp->data);
		printf("Type: %d\n", tmp->type);
		tmp = tmp->next;
	}
	return (token);
}

// The tokenization function takes an array of strings as input and processes each string.
// It creates a linked list of tokens,
// where each token has a data field (the string itself) and a type field (the type of token).
// The function uses the what_token function to determine the type of each token based on its content.
