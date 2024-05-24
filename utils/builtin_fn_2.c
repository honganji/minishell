/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:18:51 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 10:08:26 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief Free array of array.
 * 
 * Basically use this to free an array of array made ft_split
 *
 * @param arr array of array
 * @return void
 */
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	if (arr[i])
		free(arr[i]);
	free(arr);
}

/**
 * @brief check if the path exists in the OS
 * 
 * Get all the path using ft_split and PATH variable in env.
 * First, assume that the param is a definite path and check if it exists.
 * Second, assume that the param is a relative path and check if it exists.
 * 
 * @param path_name path name
 * @return If the path exist, return 1. If not, return 0
*/
char	*ft_check_exist(t_data *data, char *path_name)
{
	char	**path_arr;
	char	*comb_path;
	int		i;
	char	*env_path;

	i = 0;
	env_path = getenv("PATH");
	if (!env_path)
		syntax_err(data, "Error: ", "PATH environment variable not set", 1);
	path_arr = ft_split(env_path, ':');
	while (path_arr[i])
	{
		comb_path = ft_strjoin(path_arr[i++], path_name);
		if (!access(path_name, X_OK))
		{
			free(comb_path);
			return (free_arr(path_arr), path_name);
		}
		if (!access(comb_path, X_OK))
			return (free_arr(path_arr), comb_path);
		free(comb_path);
	}
	return (free_arr(path_arr), ft_strdup(""));
}

/**
 * @brief read the content of a file
 * 
 * Using get_next_line function, you can read whole content in a file
 * @param fd file descriptor
 * @return return the content of a file. If not, you return ""
*/
char	*ft_read_file(int fd)
{
	char	*line;
	char	*str;

	str = ft_strdup("");
	line = get_next_line(fd);
	while (line && *line)
	{
		str = ft_free_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

/**
 * @brief combine two string
 * 
 * After combine two strings, free first parameter
 * @param s1 string that is allocated
 * @param s2 string that is not allocated
 * @return return the combined string 
*/
char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	if (!str)
		return (ft_strdup(""));
	return (str);
}
