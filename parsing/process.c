/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuji <yuji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:51:37 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/22 08:35:40 by yuji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	process_commands(char *input, t_data *data)
{
	char	**raw_tokens;
	t_token	*tokens;

	add_history(input);
	raw_tokens = split_with_quotes(input, ' ');
	tokens = tokenization(raw_tokens);
	parse_commands(tokens, data);
	free(raw_tokens);
	free(input);
}
// The process_commands function takes a string as input and processes it through the tokenization and parsing functions.