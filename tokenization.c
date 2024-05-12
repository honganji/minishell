/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/10 16:36:24 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	what_redir(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>')
		return (REDIR_APP_OUT);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (REDIR_HERE);
	else if (str[i] == '>')
		return (REDIR_OUT);
	else if (str[i] == '<')
		return (REDIR_IN);
	return (0);
}
// what_redir returns the type of redirection token

void	tokenization(char **blocks)
{
	t_token	*token;
	t_token	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = token_init();
	tmp = token;
	while (blocks[i])
	{
		while (blocks[i][j])
		{
			tmp->data = extract_token(blocks[i], &j);
			tmp->type = what_token(tmp->data);
			tmp->next = token_init();
			tmp->id = i;
			tmp = tmp->next;
		}
		i++;
		j = 0;
	}
	tmp = token;
	while (tmp && tmp->data)
	{
		printf("Token: %s\n", tmp->data);
		printf("Type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}

// The tokenization function takes an array of strings as input and processes each string.
// It creates a linked list of tokens,
// where each token has a data field (the string itself) and a type field (the type of token).
// The function uses the what_token function to determine the type of each token based on its content.

char	*extract_token(char *block, int *i)
{
	char	*start;
	char	*end;
	size_t	len;
	char	*token;

	while (block[*i] && ft_isspace(block[*i]))
		(*i)++;
	start = &block[*i];
	if (in_quotes(start))
	{
		end = ft_strchr(start + 1, start[0]);
		if (end != NULL)
			end++;
		// (*i)++;
	}
	else
	{
		end = start;
		while (*end && !ft_isspace(*end) && !in_quotes(end))
			end++;
	}
		end = ft_strchr(start, ' ');
	if (end == NULL)
		end = start + ft_strlen(start);
	len = end - start;
	token = ft_substr(start, 0, len);
	*i += len;
	return (token);
}
// The extract_token function takes an array of strings, an index i,
// and a position j as input.
// It extracts a token from the string at index i, starting at position j.
// The token is extracted by finding the first space character after position j.
// The function then creates a new string containing the token and returns it.

int	in_quotes(char *str)
{
	int	quote;
	int i;

	i = 0;
	quote = 0;
	if (str[0] != '\"' && str[0] != '\'')
		return (0);
	while (str[i])
	{
		if ((str[i] == '\"' || str[i] == '\'') && quote == 0)
			quote = 1;
		else if ((str[i] == '\"' || str[i] == '\'') && quote == 1)
			quote = 0;
		i++;
	}
	if (str[i -1] != str[0])
		return 0;
	return (quote);
}
