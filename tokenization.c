/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/08 18:45:06 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		what_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_command(str))
			return (CMD);
		else if (str[i] == '-')
			return (FLAG);
		else if (is_env_var(str))
			return (ENV_VAR);
		else if (is_argument(str))
			return (ARG);
		else if (str[i] == '|')
			return (PIPE);
		else if (str[i] == '>' || str[i] == '<')
			return (what_redir(str, i));
		else if (str[i] == '"' || str[i] == '\'')
			return (what_quote(str, i));
		i++;
	}
	return (0);
}
// what_token takes a string as input and returns the type of token

int what_quote(char *str, int i)
{
	int len = ft_strlen(str);
	int in_quotes = 0;
	char quote_char = '\0';

	while (i < len)
	{
		if (str[i] == '\\' && i + 1 < len)
		{
			ft_memmove(&str[i], &str[i + 1], len - i);
			len--;
			continue;
		}
		if (in_quotes)
		{
			if (str[i] == quote_char)
				in_quotes = 0;
		}
		else
		{
			if (str[i] == '"' && str[len - 1] == '"')
			{
				in_quotes = 1;
				quote_char = str[i];
				return (D_QUOTE);
			}
			else if (str[i] == '\'' && str[len - 1] == '\'')
			{
				in_quotes = 1;
				quote_char = str[i];
				return (QUOTE);
			}
		}
		i++;
	}
	return (0);
}
// what_quote returns the type of quote token

int	what_redir(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>')
		return (REDIR_APP_OUT);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (REDIR_HERE);
	else if (str[i] == '>')
		return (REDIR_OUT);
	else if (str[i] == '<')
		return (REDIR_IN);
	return (0);
}
// what_redir returns the type of redirection token

int	is_command(char *str)
{
	int		i;
	int		len;
	char	*valid_commands[] = {"echo", "cd", "pwd", "export", "unset", "env",
			"exit", NULL};

	i = 0;
	len = 0;
	while (valid_commands[i] != NULL)
	{
		len = ft_strlen(valid_commands[i]);
		if (ft_strncmp(str, valid_commands[i], len) == 0)
			return (1);
		i++;
	}
	return (0);
}
// The is_command function takes a string as input and checks if it is a valid command.
// It compares the string with a list of valid commands and returns 1 if the string is a valid command,	and 0 otherwise.

int	is_env_var(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (0);
	while (j < i)
	{
		if (!((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A'
					&& str[j] <= 'Z') || (str[j] == '_') || (j > 0
					&& str[j] >= '0' && str[j] <= '9')))
			return (0);
		j++;
	}
	return (1);
}
// The is_env_var function takes a string as input and checks if it is an environment variable.
// It checks if the string contains an equal sign (=) and if the characters before the equal sign are valid environment variable characters.
// Environment variables are made up of letters, numbers, and underscores, and must start with a letter or underscore.

int	is_argument(char *str)
{
	int		len;
	int		in_quotes;
	int		i;
	char	quote_char;

	in_quotes = 0;
	i = 0;
	quote_char = '\0';
	len = ft_strlen(str);
	if (is_command(str) || ft_strncmp(str, "|", 2) == 0 || ft_strncmp(str, ">",
			2) == 0 || ft_strncmp(str, "<", 2) == 0)
		return (0);
	while (i < len)
	{
		if (str[i] == '\\' && i + 1 < len)
		{
			ft_memmove(&str[i], &str[i + 1], len - i);
			len--;
			continue ;
		}
		if (in_quotes)
		{
			if (str[i] == quote_char)
				in_quotes = 0;
		}
		else
		{
			if ((str[i] == '"' || str[i] == '\'') && len > 1)
			{
				in_quotes = 1;
				quote_char = str[i];
			}
		}
		i++;
	}
	if (in_quotes)
		return (1);
	return (0);
}

bool	in_quotes(char *str)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if(str[i] == '"' || str[i] == '\'')
		{
			j = i + 1;
			while (str[j] && str[j] != '"' && str[j] != '\'')
				j++;
			if (!str[j] || (str[j] != '"' && str[j] != '\''))
				return (true);
		}
		i++;
	}
	return (false);
}

int is_flag(char *str)
{
    int i;

    // Check if the first character is '-'
    if (str[0] != '-')
        return 0;

    // Check if the rest of the characters are alphanumeric
    for (i = 1; str[i]; i++)
    {
        if (!ft_isalnum(str[i]))
            return 0;
    }
    return 1;
}

void	tokenization(char **blocks)
{
	char **tokens;
	t_token	*token;
	t_token	*tmp;
	int		i;

	i = 0;
	tokens = ft_split(blocks[i], ' ');
	token = token_init();
	tmp = token;
	while (tokens[i])
	{
		tmp->data = tokens[i];
		tmp->type = what_token(tokens[i]);
		tmp->next = token_init();
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
	tmp = token;
	while (tmp && tmp->data)
	{
		printf("Token: %s\n", tmp->data);
		printf("Type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}
// The tokenization function takes an array of strings as input and processes each string.
// It creates a linked list of tokens,
//	where each token has a data field (the string itself) and a type field (the type of token).
// The function uses the what_token function to determine the type of each token based on its content.

void	