/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/09 14:28:32 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"

typedef struct s_data t_data;

void	ft_store_env(t_data *data, char **environ);

#endif