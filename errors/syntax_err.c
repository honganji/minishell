/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/22 11:04:40 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/errors.h"

void set_exit_code(t_data *data, int code)
{
	data->exit_code = code;
}

void syntax_err(t_data *data, char *str, char *cmd, int code)
{
	set_exit_code(data, code);
	printf("minishell: %s: %s\n", cmd, str);
}
