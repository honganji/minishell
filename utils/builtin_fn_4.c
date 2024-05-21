/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:22:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 12:16:47 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief Accept input until you face EOF
 *
 * @param data data
 * @param eof end of file
 * @return void
 * 
 */
void    input_heredoc(t_data *data, char *eof)
{
	char	*str;
	char	*tmp;

	str = readline("> ");
	while (!ft_strnstr(str, eof, ft_strlen(str)))
	{
		printf("> ");
        rl_redisplay();
		tmp = readline("");
		str = ft_free_strjoin(str, tmp);
		str = ft_free_strjoin(str, "\n");
	}
	ft_input_data(data, str, 0);
}
