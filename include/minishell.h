/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 18:04:33 by adprzyby         ###   ########.fr       */
=======
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:24:45 by ytoshihi         ###   ########.fr       */
>>>>>>> develop
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

<<<<<<< HEAD
	// LIBS

# include "../42-c-library/library.h"
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
	NOTOKEN,		// no token (0)
	WORD,          // a sequence of characters (command, argument, etc.) (1)
	PIPE,          // | (2)
	REDIR_HERE,    // << (3)
	REDIR_APP_OUT, // >> (4)
	REDIR_IN,      // < (5)
	REDIR_OUT,     // > (6)
}					t_type;

// A type is a category of a token.

typedef struct s_token
{
	void			*data;
	enum s_type		type;
	int				id;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

// A token is a single, indivisible unit of a program.
// In the context of a shell, a token is a single word or symbol.
// 		For example, in the command ls -l, there are two tokens: ls and -l.

typedef struct s_cmd
{
	char			**args;
	char			*input;
	char			*output;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

// A command is a sequence of words that the shell executes.
// 		For example, in the command ls -l, ls is the command and
// -l is an argument.
// A command can also have input and output redirection, as well as pipes.

typedef struct s_split_vars
{
	int				start;
	int				end;
	int				index;
	int				in_s_quotes;
	int				in_d_quotes;
}					t_split_vars;

// A struct to store variables used in the split_with_quotes function

	// FUNCTIONS

// main
int					main(int argc, char **argv, char **envp);

// tokenization
t_token				*tokenization(char **tokens);
int					what_token(char *str);
int					what_redir(char *str, int i);
// int				is_command(char *str);
// int				is_env_var(char *str);
// int				is_argument(char *str);
// int				is_flag(char *str);

// init
t_token				*token_init(void);
t_env				*env_init(char **envp);
t_cmd				*cmd_init(void);
// t_cmd			*cmd_list_init(void);

// utils
int					ft_isspace(int c);
int					in_quotes(char *str);

// split
char				**split_with_quotes(char const *s, char c);
char				*word_dup(int start, int end, char const *str);
int					count_word(char const *s, char c);
void				check_chr(char const *s, int *end, char c);
char				**free_arr(char **tokens);

// parsing
void				parse_commands(t_token *tokens);
void				add_token_to_command(t_cmd *command, t_token *token);
void				add_command_to_list(t_cmd **head, t_cmd *command);
void				process_commands(char *input);
void 				print_commands(t_cmd *command);
=======
# define TMP_FILE "utils/tmp.txt"

# include "execution.h"
# include "env.h"
# include "pipe.h"
// TODO delete
# include "test.h"

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"

typedef enum e_com
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	ETC
}t_com;

typedef struct s_env
{
	char	*key;
	char	*value;
}t_env;

typedef struct s_data
{
	t_list	*env_lst;
}t_data;

typedef struct s_exe
{
	t_com	com;
	char	*str;
}t_exe;
>>>>>>> develop

#endif