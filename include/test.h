/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:23:10 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 20:11:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO delete

#ifndef TEST_H
# define TEST_H

#include "minishell.h"

typedef struct s_data t_data;
typedef struct s_exe t_exe;

void	set_val(t_data *data, t_exe **arr, char **env);
void	pipe_test(t_data *data, t_exe *arr);
void	command_test(t_data *data);
void	red_test(t_data *data);

#endif