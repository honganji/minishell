/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 19:10:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// LIBS

# include "./42-c-library/library.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// STRUCTS

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

// Environment variables are a feature of Unix and Unix-like operating systems,
//  and they are used to modify the behavior of running processes.
// Environment variables are made up of a name (or key) and a value.
// 		For example, in the environment variable PATH=/usr/bin:/bin,
// PATH is the key and /usr/bin:/bin is the value.

typedef enum s_type
{
	NOTOKEN,
	WORD,		  // a sequence of characters (command, argument, etc.)
	PIPE,          // |
	REDIR_HERE,    // <<
	REDIR_APP_OUT, // >>
	REDIR_IN,      // <
	REDIR_OUT,     // >
	// QUOTE,         // '
	// D_QUOTE,       // "
	// BRACE_EXP      // {}
}				t_type;

// A type is a category of a token.

typedef struct s_token
{
	void			*data;
	enum	s_type	type;
	int				i;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

// A token is a single, indivisible unit of a program.
// In the context of a shell, a token is a single word or symbol.
// 		For example, in the command ls -l, there are two tokens: ls and -l.


typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	char			*input;
	char			*output;
	int				pipe;
	int				pipefd[2];
}					t_cmd;

// A command is a sequence of words that the shell executes.
// 		For example, in the command ls -l, ls is the command and
// -l is an argument.
// A command can also have input and output redirection, as well as pipes.

// FUNCTIONS

// main
int					main(int argc, char **argv, char **envp);

// tokenization
void				tokenization(char **tokens);
int					what_token(char *str);
int					what_quote(char *str, int i);
int					what_redir(char *str, int i);
int					is_command(char *str);
int					is_env_var(char *str);
int					is_argument(char *str);

// init
t_token				*token_init(void);
t_env				*env_init(char **envp);

#endif