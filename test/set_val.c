/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:32:42 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:56:53 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	set_val(t_data *data, t_exe **arr, char **env)
{
	// store commands
	*arr = (t_exe *)ft_calloc(4, sizeof(t_exe));
	(*arr)[0].com = ECHO;
	(*arr)[0].str = ".";
	(*arr)[1].com = ETC;
	(*arr)[1].str = "/ls -a";
	(*arr)[2].com = ECHO;
	(*arr)[2].str = "WOW";

	// get env variables
	ft_store_env(data, env);

	// initialize the stdin
	ft_input_data("", 0);
}
