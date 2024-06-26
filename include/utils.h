/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:57:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/05 18:10:23 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../42-c-library/library.h"
# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef struct s_env	t_env;
typedef struct s_exe	t_exe;

void					ft_del_node(t_data *data, t_list *lst, t_list *pre_lst);
t_list					*ft_find_ele(t_data *data, char *str);
char					*ft_rep_env(t_data *data, char *str);
void					ft_to_json(char **env_json, char *env_name);
void					free_arr(char **arr);
char					*ft_check_exist(t_data *data, char *path_name);
void					ft_input_data(t_data *data, char *str, int is_file);
char					*ft_read_file(int fd);
char					*ft_free_strjoin(char *s1, char *s2);
int						ft_isspace(int c);
char					**split_with_quotes(char const *s, char c);
char					*word_dup(int start, int end, char const *str);
int						count_word(char const *s, char c);
void					check_chr(char const *s, int *end, char c);
void					set_sig(int sig);
void					check_signal(t_data *data);
char					*ft_join_with_space(char **args);
void					register_env(t_data *data, char *key, char *value);
void					input_heredoc(t_data *data, char *eof);
char					*replace_env(t_data *data, char *str);
void					remove_quote(char **str, int *is_skip);
void					store_ec(t_data *data, int status, int fds[2],
							pid_t pid);
void					exe_builtin(int fds[2], char **args);
void					update_env_var(t_data *data, t_env *env_json,
							char **env_arr);
char					*join_to_env(char *str, t_list *env_list);
char					*join_to_export(char *str, t_list *env_list);
void					handle_no_args(t_data *data, char *arg);
void					handle_args(char *arg, char **env_arr, t_env *env_json);
void					free_env_lst(t_data *data);
void					free_cmd_lst(t_data *data);
void					free_token(t_token *token);
void					free_data(t_data *data);
int						ft_str_isdigit(char *str);
int						check_minus(char *str);
int						arr_len(char **arr);
int						ft_isstr_alpha(char *str);
void					setup_arg(t_exe *params, char **args, t_data *data);
int						redir_check(t_data *data, t_token *tmp);
char					*ft_strndup(const char *s, size_t n);

#endif