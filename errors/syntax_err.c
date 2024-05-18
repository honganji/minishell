/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/18 12:14:22 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void set_exit_code(t_data *data, int code)
{
	data->exit_code = code;
}

void syntax_err(t_data *data, char *str, char *cmd, int code)
{
	set_exit_code(data, code);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
}

