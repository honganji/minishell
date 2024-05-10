/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:58 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/10 22:20:54 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"

void	ft_create_pipe(void);
void	ft_output_red(char *name, char *content, int is_append);
void	ft_input_file(char *str, int is_file);

#endif