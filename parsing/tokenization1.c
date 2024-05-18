/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:25:36 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/16 19:07:33 by adprzyby         ###   ########.fr       */
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
// TODO: Handle esc chars
void	handle_esc_chars(t_token *token)
{
	(*str)++;
	if (**str == 'n')
		add_char_to_token('\n', token);
	else if (**str == 't')
		add_char_to_token('\t', token);
	else
		add_char_to_token(**str, token);
	(*str)++;
}
