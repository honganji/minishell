/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:43:20 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 17:34:31 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	store_output(t_data* data)
{
	int file_desc;

	file_desc = open(TMP_FILE, O_RDONLY);
	free(data->output);
	data->output = ft_read_file(file_desc);
	ft_input_data(data->output, 0);
	// printf("stdin: %s", data->output);
	if (unlink(TMP_FILE))
		perror("error in unlinking");
}