/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/14 15:09:53 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = readline("Enter command: ");
		if (input)
		{
			process_commands(input);                       
		}
	}
	return (0);
}

// envp parameter is not part of the standard C specification,
// but it is a common extension
// and is generally portable across Unix-like systems,
// including macOS and Linux.
// On systems where it is not available,
// environment variables can usually be accessed through the "getenv" function.
