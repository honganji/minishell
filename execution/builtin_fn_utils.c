/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:24:36 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 09:26:58 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_del_node(t_data **data, t_list **lst, t_list *pre_lst)
{
	if (!pre_lst)
	{
		free(*lst);
		(*data)->env_lst = (*data)->env_lst->next;
		return ;
	}
	else
	{
		pre_lst->next = (*lst)->next;
		free(*lst);
		return ;
	}
}
