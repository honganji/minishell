/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/11 13:31:26 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

void	ft_output_red(char *name, char *content, int is_append)
{
	int	fd;

	open(name, O_CREAT, 0744);
	if (is_append)
		fd = open(name, O_WRONLY);
	else
		fd = open(name, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("opening file error");
		return ;
	}
	write(fd, content, ft_strlen(content));
	close(fd);
}

int	main(void)
{
	ft_output_red("text_1.txt", "Hello World!", 1);
	ft_output_red("text_2.txt", "Hello World!", 0);
	ft_input_data("text_2.txt", 1);
	ft_execve("/sort");
	printf("\n");
	ft_input_data("Hello\nYou\nKing\n", 0);
	ft_execve("/sort");
	return (0);
}
