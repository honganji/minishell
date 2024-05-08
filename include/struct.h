/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:07:23 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:10:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	char	**args;
	char	*path;
	t_env	*arr;
	t_list	*env_lst;
}t_data;

#endif