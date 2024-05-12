/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/12 18:31:12 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_cmd_list **commands;
	// Print all environment variables
	char **env = envp;
	while (*env != 0)
	{
		char *thisEnv = *env;
		printf("%s\n", thisEnv);
		env++;
	}
	// Not used argc and argv
	(void)argc;
	(void)argv;
	// Main loop for the shell
	while (1)
	{
		char* input = readline("Enter command: ");
		if (input)
		{
			add_history(input);  // add the input to the history
			char **raw_tokens = split_with_quotes(input, ' ');  // split the input into blocks separated by ' '
			tokenization(raw_tokens);  // process the tokens
			commands = parse_commands();  // group the tokens into commands
			free(raw_tokens);  // free the memory allocated by ft_split
			free(input);  // free the memory allocated by readline
		}
	}
	return (0);
}

//envp parameter is not part of the standard C specification, but it is a common extension
// and is generally portable across Unix-like systems, including macOS and Linux.
// On systems where it is not available, environment variables can usually be accessed through the "getenv" function.
