/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:57:07 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (count);
		while (*s != c && *s)
			s++;
		count++;
	}
	return (count);
}

char	*word_dup(int start, int end, const char *str)
{
	char	*word;
	int		size;

	size = end - start;
	word = (char *)malloc((size + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (size--)
		word[end - start - size - 1] = str[start + (end - start - size - 1)];
	word[end - start] = '\0';
	return (word);
}

char	**free_arr(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		free(tokens[count++]);
	free(tokens[count]);
	free(tokens);
	return (NULL);
}

void	check_chr(char const *s, int *end, char c)
{
	while (s[*end] == c)
		(*end)++;
}

// char	**split_with_quotes(char const *s, char c)
// {
// 	char	**tokens;
// 	int		start;
// 	int		end;
// 	int		index;
// 	int		in_s_quotes;
// 	int		in_d_quotes;

// 	tokens = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
// 	start = 0;
// 	end = 0;
// 	index = 0;
// 	in_s_quotes = 0;
// 	in_d_quotes = 0;
// 	if (!s || !tokens)
// 		return (NULL);
// 	while (s[end])
// 	{
// 		check_chr(s, &end, c);
// 		start = end;
// 		if (!s[end])
// 			break ;
// 		while (s[end] && (s[end] != c || in_s_quotes || in_d_quotes))
// 		{
// 			if (s[end] == '\'')
// 				in_s_quotes = !in_s_quotes;
// 			else if (s[end] == '\"')
// 				in_d_quotes = !in_d_quotes;
// 			end++;
// 		}
// 		tokens[index] = word_dup(start, end, s);
// 		if (!tokens[index++])
// 			return (free_arr(tokens));
// 	}
// 	tokens[index] = NULL;
// 	return (tokens);
// }
