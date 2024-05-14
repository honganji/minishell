/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:28:41 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/14 16:45:45 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "minishell.h"

typedef struct s_token t_token;
typedef struct s_cmd t_cmd;

t_token				*token_init(void);
t_env				*env_init(char **envp);
t_cmd				*cmd_init(void);

#endif