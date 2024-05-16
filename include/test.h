/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:23:10 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/16 21:12:33 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO delete

#ifndef TEST_H
# define TEST_H

#include "minishell.h"

typedef struct s_data t_data;
typedef struct s_exe t_exe;
typedef struct s_redir t_redir;

void	set_val(t_data *data, char **env);
void	pipe_test(t_data *data);
void	red_test(t_data *data);

#endif