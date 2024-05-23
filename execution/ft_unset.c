/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:25:05 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 11:51:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief export value into env linked list
 * 
 * @param data data
 * @param str string include key and value connected with '='
 * @return void
 */
void	ft_unset(t_data *data)
{
	char	*key;
	t_list	*pre_lst;
	t_list	*tmp_lst;
	char	*str;

	pre_lst = NULL;
	tmp_lst = data->env_lst;
	str = ((t_cmd *)data->cmd_lst->content)->args[1];
	if (!str)
	{
		ft_input_data(data, "", 0);
		return ;
	}
	while (tmp_lst)
	{
		key = (*(t_env *)((tmp_lst)->content)).key;
		if (!ft_strncmp(key, str, ft_strlen(str)))
			ft_del_node(data, tmp_lst, pre_lst);
		pre_lst = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	ft_input_data(data, "", 0);
	data->exit_code = 0;
}
