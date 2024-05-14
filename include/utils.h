/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:57:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:12:41 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../42-c-library/library.h"
# include "minishell.h"

typedef struct s_data t_data;

void	ft_del_node(t_data *data, t_list *lst, t_list *pre_lst);
t_list	*ft_find_ele(t_data *data, char *str);
char	*ft_rep_env(t_data *data, char *str);
void	ft_to_json(char **env_json, char *env_name);
void	free_arr(char **path_arr);
char	*ft_check_exist(char *path_name);
void	ft_input_data(char *str, int is_file);
char	*ft_read_file(int fd);
char	*ft_free_strjoin(char *s1, char *s2);
void	store_output(void);

#endif