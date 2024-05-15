/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 16:33:09 by adprzyby         ###   ########.fr       */
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
# define TMP_FILE "utils/tmp.txt"

# include "env.h"
# include "execution.h"
# include "pipe.h"
// TODO delete
# include "../42-c-library/library.h"
# include "test.h"
# include <sys/wait.h>
# include <unistd.h>

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
}					t_com;

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct s_data
{
	t_list			*env_lst;
	int				exit_code;
}					t_data;

typedef struct s_exe
{
	t_com			com;
	char			**args;
	char			*input;
	char			*output;
}					t_exe;

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

// typedef struct s_cmd
// {
// 	char			**args;
// 	char			*input;
// 	char			*output;
// 	struct s_cmd	*next;
// 	struct s_cmd	*prev;
// }					t_cmd;

typedef struct s_split_vars
{
	int				start;
	int				end;
	int				index;
	int				in_s_quotes;
	int				in_d_quotes;
}					t_split_vars;

#endif