/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:45 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/24 17:17:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief input data for STDIN_FILENO
 * 
 * You can decide which format string or file.
 * @param str file path or string data
 * @param is_file flag if the data is string or is located in a file
 * @return void
*/
void	ft_input_data_from_file(t_data *data, char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		syntax_err(data, "Error opening file: ", str, 1);
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

/**
 * @brief put string into STDIN-fd
 * 
 * @param data whole data
 * @param str string to use as input
 * @return void
*/
void	ft_input_data_from_string(t_data *data, char *str)
{
	int		fds[2];

	if (pipe(fds))
	{
		syntax_err(data, "Pipe error: ", strerror(errno), 1);
		return ;
	}
	if (write(fds[1], str, ft_strlen(str)) == -1)
	{
		syntax_err(data, "Write error: ", strerror(errno), 1);
		close(fds[1]);
		return ;
	}
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
}

/**
 * @brief put string for file into STDIN-fd
 * 
 * @param data whole data
 * @param str string to use as input or file name
 * @param is_file flag if it is a file
 * @return void
*/
void	ft_input_data(t_data *data, char *str, int is_file)
{
	if (is_file)
		ft_input_data_from_file(data, str);
	else
		ft_input_data_from_string(data, str);
}

char	*ft_join_with_space(char **args)
{
	char	*str;
	int		i;

	str = ft_calloc(1, 1);
	i = 0;
	str = ft_free_strjoin(str, args[i++]);
	while (args[i])
	{
		str = ft_free_strjoin(str, " ");
		str = ft_free_strjoin(str, args[i++]);
	}
	return (str);
}

void	register_env(t_data *data, char *key, char *value)
{
	t_env	*env_json;
	t_list	*targ_lst;
	void	*tmp;
	// char	*key_tmp;
	// char	*value_tmp;

	env_json = (t_env *)malloc(1 * sizeof(t_env));
	if (!env_json)
		critical_err(strerror(errno));
	env_json->key = ft_strdup(key);
	env_json->value = ft_strdup(value);
	targ_lst = ft_find_ele(data, key);
	if (targ_lst)
	{
		tmp = targ_lst->content;
		targ_lst->content = env_json;
		free(((t_env *)tmp)->key);
		free(((t_env *)tmp)->value);
		free(tmp);
		// key_tmp = ((t_env *)targ_lst->content)->key;
		// value_tmp = ((t_env *)targ_lst->content)->value;
		// // TODO delete
		// printf("pointer1: %p\n", &key_tmp);
		// free(key_tmp);
		// free(value_tmp);
		// ((t_env *)targ_lst->content)->key = env_json->key;
		// // TODO delete
		// printf("pointer2: %p\n", &((t_env *)targ_lst->content)->key);
		// ((t_env *)targ_lst->content)->value = env_json->value;
		// free(env_json);

		// tmp = targ_lst->content;
		// targ_lst->content = env_json;
		// free(tmp->key);
		// free(tmp->value);
		// free(tmp);
	}
	else
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
}
