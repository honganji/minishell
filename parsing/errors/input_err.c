/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:19 by adprzyby          #+#    #+#             */
/*   Updated: 2024/04/30 16:22:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

bool	input_err(int argc)
{
	if (argc != 1)
	{
		printf("Error: invalid number of arguments\n");
		return (true);
	}
	return (false);
}
