/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:03:26 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/18 12:08:15 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"

typedef struct s_data t_data;

void	critical_err(const char *msg);
void 	set_exit_code(t_data *data, int code);

#endif