/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:51:37 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/23 17:00:55 by ytoshihi         ###   ########.fr       */
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
	free_token(tokens);
	free_arr(raw_tokens);
	free(input);
}
