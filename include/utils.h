/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:57:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 11:49:37 by ytoshihi         ###   ########.fr       */
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
void	free_arr(char **arr);
char	*ft_check_exist(t_data *data, char *path_name);
void	ft_input_data(t_data *data, char *str, int is_file);
char	*ft_read_file(int fd);
char	*ft_free_strjoin(char *s1, char *s2);
int		ft_isspace(int c);
int		in_quotes(char *str);
char	**split_with_quotes(char const *s, char c);
char	*word_dup(int start, int end, char const *str);
int		count_word(char const *s, char c);
void	check_chr(char const *s, int *end, char c);
void	set_sig(int sig);
void	check_signal(t_data *data, char *input);
char	*ft_join_with_space(char **args);
void	register_env(t_data* data, char *key, char *value);
void    input_heredoc(t_data *data, char *eof);

#endif