/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/17 17:26:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

/**
 * @brief 
 * 
 * @param 
 * @return 
 */
void	ft_output_red(char *name, char *content, int is_append)
{
	int	fd;

	if (is_append)
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0744);
	else
		fd = open(name, O_CREAT | O_WRONLY, 0744);
	if (fd == -1)
	{
		perror("opening file error");
		return ;
	}
	write(fd, content, ft_strlen(content));
	close(fd);
}
