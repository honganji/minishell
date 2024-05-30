/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:21 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/30 17:11:12 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

char	*remove_quotes(char *str)
{
	int		i;
	char	start_quote;
	char	*new_str;
	size_t	no_quotes_len;
	int		j;

	i = 0;
	j = 0;
	start_quote = first_quote(str);
	no_quotes_len = no_quotes_strlen(str, start_quote);
	new_str = (char *)calloc(no_quotes_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != start_quote)
			new_str[j++] = str[i];
		i++;
	}
	return (new_str);
}

char	first_quote(char *str)
{
	while (*str)
	{
		if (*str == '"' || *str == '\'')
			return (*str);
		str++;
	}
	return (0);
}

size_t	no_quotes_strlen(char *str, char start_quote)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str != start_quote)
			len++;
		str++;
	}
	return (len);
}
