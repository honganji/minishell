/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:58 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:15:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "struct.h"
# include "utils.h"

// typedef enum e_com	t_com;

// typedef struct s_arg
// {
// 	char 	*arg;
// 	t_com	com;
// }t_arg;

void	ft_create_pipe(void);

#endif