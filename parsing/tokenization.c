/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/19 15:07:55 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	what_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (PIPE);
		else if (str[i] == '>' || str[i] == '<')
			return (is_redir(str, i));
		else
			return (WORD);
		i++;
	}
	return (0);
}

int is_redir(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] != '\0' && str[i + 1] == '>')
		return (REDIR);
	else if (str[i] == '<' && str[i + 1] != '\0' && str[i + 1] == '<')
		return (REDIR);
	else if (str[i] == '>')
		return (REDIR);
	else if (str[i] == '<')
		return (REDIR);
	else
		return (WORD);
	return (0);
}

t_token	*tokenization(char **tokens)
{
	t_token	*token;
	t_token	*tmp;
	int		i;

	i = 0;
	token = token_init();
	tmp = token;
	while (tokens[i])
	{
		tmp->data = tokens[i];
		while (tmp->data && *tmp->data)
		{
			if (*tmp->data == '\\' && *(tmp->data + 1) != '\0')
				handle_backslash(&tmp->data);
		}
		tmp->type = what_token(tmp->data);
		tmp->next = token_init();
		tmp->id = i;
		tmp = tmp->next;
		i++;
	}
	tmp = token;
	// while (tmp && tmp->data)
	// {
	// 	printf("Token: %s\n", tmp->data);			//!DEBUG
	// 	printf("Type: %d\n", tmp->type);
	// 	tmp = tmp->next;
	// }
	return (token);
}

int	count_backslashes(char **str)
{
	int	count = 0;
	while (**str == '\\')
	{
		count++;
		(*str)++;
	}
	return count;
}

void	print_string(char *str)
{
	int	b;

	while (*str)
	{
		if (*str == '\\')
		{
			b = count_backslashes(&str);
			while (b > 0)
			{
				write(1, "\\", 1);
				b--;
			}
			if (*str == '\0')
				break ;
			write(1, str, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
