/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:22:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 14:22:30 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief get all the env variable and send them to input parameter
 * 
 * Read all the node of a env variable list and combine using ft_free_strjoin
 * @param data data
 * @return void
 */
void	ft_env(t_list *env_lst, t_data *data)
{
	t_list	*tmp;
	char	*str;

	tmp = env_lst;
	str = ft_strdup("");
	if (!str)
		critical_err(strerror(errno));
	while (tmp)
	{
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).key);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "=");
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).value);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "\n");
		if (!str)
			critical_err(strerror(errno));
		tmp = tmp->next;
	}
	ft_input_data(data, str, 0);
	return (free(str), set_exit_code(data, 0));
}
