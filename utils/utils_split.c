/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:57:07 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/18 15:51:57 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

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

void	check_chr(char const *s, int *end, char c)
{
	while (s[*end] == c)
		(*end)++;
}
