/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:25:36 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/14 18:29:30 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/parsing.h"

void	handle_double_quotes(char **str, t_token *token)
{
	(*str)++;
	while (**str != '\"' && **str != '\0')
	{
		if (**str == '$')
			handle_dollar_sign(str, token);
		else
		{
			add_char_to_token(**str, token);
			(*str)++;
		}
	}
	if (**str == '\"')
		(*str)++;
}

void add_char_to_token(char c, t_token *token)
{
	size_t len = strlen(token->data);
	if (len + 1 >= token->capacity)
	{
		token->capacity *= 2;
		char *new_data = malloc(token->capacity);
		strcpy(new_data, token->data);
		free(token->data);
		token->data = new_data;
	}
	token->data[len] = c;
	token->data[len + 1] = '\0';
}
