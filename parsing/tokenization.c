/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/04 14:22:46 by ytoshihi         ###   ########.fr       */
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

t_token	*tokenization(char **tokens)
{
	t_token	*token;
	t_token	*tmp;
	int		i;
	t_token	*new_token;
	t_token	*prev;

	i = 0;
	token = token_init();
	tmp = token;
	while (tokens[i])
	{
		tmp->data = ft_strdup(tokens[i]); // Allocate memory for the token data
		new_token = split_combined_tokens(tmp);
		if (new_token != tmp)
		{
			// If a new token was created, link it to the list
			if (tmp == token)
			{
				token = new_token;
			}
			else
			{
				prev = token;
				while (prev->next != tmp)
					prev = prev->next;
				prev->next = new_token;
			}
			tmp = new_token->next;
		}
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

t_token	*split_combined_tokens(t_token *token)
{
	int		i;
	int		len;
	int		j;
	t_token	*new_token;
	char	*new_data;
	int		in_quotes;

	i = 0;
	j = 0;
	len = ft_strlen(token->data);
	while (i < len)
	{
		if (token->data[i] == '<' || token->data[i] == '>')
		{
			// Check if the token is inside quotes
			in_quotes = 0;
			while (j < i)
			{
				if (token->data[j] == '"' || token->data[j] == '\'')
					in_quotes = !in_quotes;
				j++;
			}
			if (in_quotes)
				break ;
			// Check for valid redirections followed by a pipe or invalid redirections
			if ((i == 0 || (i > 0 && (token->data[i - 1] == '<' || token->data[i
							- 1] == '>'))) && (token->data[i + 1] == '|'
					|| (i == 0 && token->data[i + 1] == '|' && token->data[i
						+ 2] == '\0')))
			{
				// Handle cases like <|, >|, <<|, >>|
				new_token = token_init();
				new_token->data = ft_strndup(token->data, i + 1);
				new_token->type = what_token(new_token->data);
				new_data = ft_strdup(token->data + i + 1);
				free(token->data);
				token->data = new_data;
				token->type = what_token(token->data);
				new_token->next = token;
				return (new_token);
			}
			else if ((token->data[i] == '>' && token->data[i + 1] == '>')
				|| (token->data[i] == '<' && token->data[i + 1] == '<'))
				// Handle valid redirections: >> and <<
				i++;
			else
			{
				// Handle invalid redirections: >>>, <<<<, ><
				new_token = token_init();
				new_token->data = ft_strndup(token->data, i + 1);
				new_token->type = what_token(new_token->data);
				new_data = ft_strdup(token->data + i + 1);
				free(token->data);
				token->data = new_data;
				token->type = what_token(token->data);
				new_token->next = token;
				return (new_token);
			}
		}
		i++;
	}
	return (token);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new;

	len = 0;
	while (len < n && s[len] != '\0')
		len++;
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	return (ft_memcpy(new, s, len));
}
