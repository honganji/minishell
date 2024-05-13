/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:07:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:24:45 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

#endif