#include "minishell.h"

int	is_command(char *str)
{
	int		i;
	int		len;
	char	*valid_commands[] = {"echo", "cd", "pwd", "export", "unset", "env",
			"exit", "ls", NULL};

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

    i = 0;
    if (str[0] != '-')
        return 0;
    for (i = 1; str[i]; i++)
    {
        if (!ft_isalnum(str[i]))
            return 0;
    }
    return 1;
}
// The is_flag function takes a string as input and checks if it is a flag.