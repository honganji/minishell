/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:12 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/21 12:43:41 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

char	**initialize_split(char const *s, char c, t_split_vars *vars)
{
	char	**tokens;

	tokens = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	vars->start = 0;
	vars->end = 0;
	vars->index = 0;
	vars->in_s_quotes = 0;
	vars->in_d_quotes = 0;
	if (!s || !tokens)
		return (NULL);
	return (tokens);
}

void	process_string(char const *s, char c, char **tokens, t_split_vars *vars)
{
	while (s[vars->end])
	{
		check_chr(s, &(vars->end), c);
		vars->start = vars->end;
		if (!s[vars->end])
			break ;
		while (s[vars->end] && (s[vars->end] != c || vars->in_s_quotes
				|| vars->in_d_quotes))
		{
			if (s[vars->end] == '\'')
				vars->in_s_quotes = !(vars->in_s_quotes);
			else if (s[vars->end] == '\"')
				vars->in_d_quotes = !(vars->in_d_quotes);
			(vars->end)++;
		}
		tokens[vars->index] = word_dup(vars->start, vars->end, s);
		if (!tokens[(vars->index)++])
			free_arr(tokens);
	}
	tokens[vars->index] = NULL;
}

char	**split_with_quotes(char const *s, char c)
{
	t_split_vars	vars;
	char			**tokens;

	tokens = initialize_split(s, c, &vars);
	if (!tokens)
		return (NULL);
	process_string(s, c, tokens, &vars);
	return (tokens);
}
