/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:43:55 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/05 14:51:45 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_token	*create_new_token(t_token *token, int i)
{
	t_token	*new_token;
	char	*new_data;

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

int	check_in_quotes(t_token *token, int i)
{
	int	j;
	int	in_quotes;

	j = 0;
	in_quotes = 0;
	while (j < i)
	{
		if (token->data[j] == '"' || token->data[j] == '\'')
			in_quotes = !in_quotes;
		j++;
	}
	return (in_quotes);
}

t_token	*check_redirections(t_token *token, int i)
{
	if (i == 0 || (i > 0 && (token->data[i - 1] == '<'
				|| token->data[i - 1] == '>')))
	{
		if (token->data[i + 1] == '|' || (i == 0 && token->data[i + 1] == '|'
				&& token->data[i + 2] == '\0'))
			return (create_new_token(token, i));
	}
	if ((token->data[i] == '>' && token->data[i + 1] == '>')
		|| (token->data[i] == '<' && token->data[i + 1] == '<'))
		return (token);
	return (create_new_token(token, i));
}

t_token	*split_combined_tokens(t_token *token)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(token->data);
	while (i < len)
	{
		if (token->data[i] == '<' || token->data[i] == '>')
		{
			if (check_in_quotes(token, i))
				break ;
			token = check_redirections(token, i);
			if (token->next != NULL)
				return (token);
		}
		i++;
	}
	return (token);
}
