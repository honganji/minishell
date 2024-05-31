/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:51:37 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/31 15:19:48 by adprzyby         ###   ########.fr       */
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
	if (check_syntax(data, tokens) == 1)
		return ;
	parse_commands(tokens, data);
	free_arr(raw_tokens);
	free_token(tokens);
	free(input);
}
