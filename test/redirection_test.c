/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:09:54 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 21:39:00 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	red_test(t_data *data)
{
	(void)data;
	printf("\nred_test\n");
	ft_output_red("../text_1.txt", "overwrite output\nHello world", 1);
	ft_output_red("../text_2.txt", "\nadd output\nHello World!", 0);
	ft_input_data("../text_2.txt", 1);
	ft_execve("/sort");
	ft_input_data("Hello\nYou\nKing\n", 0);
	ft_execve("/sort");
}
