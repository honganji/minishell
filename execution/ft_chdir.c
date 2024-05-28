/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:24:33 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 20:02:35 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief Register the directory path as $OLDPWD
 * 
 * @param data data
 * @return void
 */
static void	reg_cur_dir(t_data *data)
{
	char	*cur_dir;
	char	buffer[256];

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
	{
		syntax_err(data, "pwd: error retrieving current directory\n", NULL, 1);
		ft_input_data(data, "", 0);
		return ;
	}
	register_env(data, "OLDPWD", cur_dir);
}

/**
 * @brief change the current directory to path
 * 
 * @param data data
 * @param path path to be
 * @return void
 */
static void	change_dir(t_data *data, char *path)
{
	path = strdup(path);
	reg_cur_dir(data);
	if (chdir(path) == -1)
	{
		path = ft_strjoin(path, ": No such file or directory");
		syntax_err(data, path, "cd", 1);
		ft_input_data(data, "", 0);
		return (free(path));
	}
	return (free(path));
}

/**
 * @brief change the current directory to $HOME
 * 
 * @param data data
 * @param arg argument
 * @return int
 */
static int	cd_home(t_data *data, char *arg)
{
	t_list	*tmp;
	char	*path;

	if (!arg)
	{
		tmp = ft_find_ele(data, "HOME");
		if (!tmp)
		{
			syntax_err(data, "HOME not set", "cd", 1);
			ft_input_data(data, "", 0);
			return (1);
		}
		path = ((t_env *)tmp->content)->value;
		change_dir(data, path);
		ft_input_data(data, "", 0);
		set_exit_code(data, 0);
		return (0);
	}
	return (-1);
}

/**
 * @brief change the current directory to $OLDPWD
 * 
 * @param data data
 * @param arg argument
 * @return int
 */
static int	cd_oldpwd(t_data *data, char *arg)
{
	t_list	*tmp;
	char	*path;
	char	buffer[256];
	char	*cur_dir;

	if (ft_strnstr(arg, "-", 1))
	{
		tmp = ft_find_ele(data, "OLDPWD");
		if (!tmp)
		{
			syntax_err(data, "OLDPWD not set", "cd", 1);
			ft_input_data(data, "", 0);
			return (1);
		}
		path = ((t_env *)tmp->content)->value;
		change_dir(data, path);
		cur_dir = ft_strjoin(getcwd(buffer, sizeof(buffer)), "\n");
		ft_input_data(data, cur_dir, 0);
		free(cur_dir);
		set_exit_code(data, 0);
		return (0);
	}
	return (-1);
}

/**
 * @brief change the current directory
 * After change the current directory, set empty string into STDIN
 * @param path path for the new path. It can be definite or relative path
 * @return void
 */
void	ft_chdir(char **args, t_data *data)
{
	int		result;

	result = cd_home(data, args[1]);
	if (!result || result == 1)
		return ;
	result = cd_oldpwd(data, args[1]);
	if (!result || result == 1)
		return ;
	change_dir(data, args[1]);
	ft_input_data(data, "", 0);
	set_exit_code(data, 0);
}
