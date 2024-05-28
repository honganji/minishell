/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 11:57:14 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../42-c-library/library.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <termios.h>
# include "env.h"
# include "execution.h"
# include "pipe.h"
# include "parsing.h"
# include "init.h"
# include "errors.h"
# include "set_signal.h"

// int	g_sig;

typedef struct s_redir
{
	int		is_single;
	char	*file_name;
}	t_redir;

typedef struct s_data
{
	t_list	*env_lst;
	t_list	*cmd_lst;
	int		exit_code;
	int		stdin_fd;
}t_data;

typedef enum e_com
{
	ECH,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	ETC
}					t_com;

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct s_cmd
{
	t_com	com;
	char	**args;
	t_redir	input;
	t_redir	output;
}t_cmd;

typedef enum s_type
{
	NOTOKEN,
	WORD,
	PIPE,
	REDIR
}					t_type;

typedef struct s_token
{
	char			*data;
	enum s_type		type;
	int				id;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_split_vars
{
	int				start;
	int				end;
	int				index;
	int				in_s_quotes;
	int				in_d_quotes;
}					t_split_vars;

#endif