/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:43:20 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 13:48:21 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief store output after running a builtin function
 * 
 * Before running this project, you need to output the result of a builtin fn
 * into a file. Then, read the file and put the result into STDIN
 *
 * @param void
 * @return void
 */
void	store_output(void)
{
	int		file_desc;
	char	*str;

	file_desc = open(TMP_FILE, O_RDONLY);
	str = ft_read_file(file_desc);
	ft_input_data(str, 0);
	free(str);
}
