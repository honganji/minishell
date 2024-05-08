/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:57:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:15:14 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../42-c-library/library.h"
# include "struct.h"

void	ft_del_node(t_data *data, t_list *lst, t_list *pre_lst);
t_list	*ft_find_ele(t_data *data, char *str);
char	*ft_rep_env(t_data *data, char *str);
void	ft_to_json(char **env_json, char *env_name);
void	free_arr(char **path_arr);
char	*ft_check_exist(char *path_name);

#endif