/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:28:41 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 22:00:53 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "minishell.h"

typedef struct s_token t_token;
typedef struct s_cmd t_cmd;

t_token				*token_init(void);
t_cmd				*cmd_init(void);
void                initialize(t_data *data, char **env);

#endif