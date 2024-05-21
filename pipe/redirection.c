/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 15:17:36 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

/**
 * @brief Outputs the content to the file.
 * 
 * @param name The name of the file to output.
 * @return fd The file descriptor.
 */
int	ft_output_red(char *name, char *content, int is_ow)
{
	int	fd;

	if (is_ow)
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0744);
	else
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0744);
	if (fd == -1)
		return (-1);
	if (write(fd, content, ft_strlen(content)))		//! I added a check for write
	{
		close(fd);
		return (-1);
	}			
	close(fd);
	return(0);
}
