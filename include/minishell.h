/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/17 15:43:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../42-c-library/library.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define TMP_FILE "tmp.txt"

# include "execution.h"
# include "env.h"
# include "pipe.h"
# include "parsing.h"
# include "init.h"
// TODO delete
# include "test.h"

# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"

typedef struct s_data
{
	t_list	*env_lst;
	t_list	*cmd_lst;
	int		exit_code;
}t_data;

typedef enum e_com
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	OUTPUT,
	ETC
}t_com;

typedef struct s_env
{
	char	*key;
	char	*value;
}t_env;

typedef struct s_redir
{
	int		is_single;
	char	*file_name;
}t_redir;

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
	REDIR_HERE,
	REDIR_APP_OUT,
	REDIR_IN,
	REDIR_OUT,
}					t_type;

typedef struct s_token
{
	void			*data;
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