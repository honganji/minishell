/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/06 17:12:56 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	main(void)
{
	char	**args;

	args = ft_split("ls -l", ' ');
	ft_create_pipe(0);
	printf("main function\n");
	printf("This function shouldn't be run\n");
	return (0);
}
