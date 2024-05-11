/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/11 13:09:24 by ytoshihi         ###   ########.fr       */
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

// TODO delete this because this is also in builtin_fn_2.c in utils
void	ft_st_input_file(char *str, int is_file)
{
	int		fds[2];

	if (is_file)
	{
		fds[0] = open(str, O_RDONLY);
		if (fds[0] == -1)
		{
			perror("opening file error");
			return ;
		}
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	else
	{
		if (pipe(fds))
		{
			perror("pipe error");
			return ;
		}
		write(fds[1], str, ft_strlen(str));
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
}

int	main(void)
{
	ft_output_red("text_1.txt", "Hello World!", 1);
	ft_output_red("text_2.txt", "Hello World!", 0);
	ft_st_input_file("text_2.txt", 1);
	ft_execve("/sort");
	printf("\n");
	ft_st_input_file("Hello\nYou\nKing\n", 0);
	ft_execve("/sort");
	return (0);
}
