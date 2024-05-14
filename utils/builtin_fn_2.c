/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:18:51 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/14 16:26:30 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	free_arr(char **path_arr)
{
	int	i;

	i = 0;
	while (path_arr[i])
		free(path_arr[i++]);
	free(path_arr[i]);
	free(path_arr);
}

char	*ft_check_exist(char *path_name)
{
	char	**path_arr;
	char	*comb_path;
	int		i;

	i = 0;
	path_arr = ft_split(getenv("PATH"), ':');
	while (path_arr[i])
	{
		comb_path = ft_strjoin(path_arr[i++], path_name);
		if (!access(path_name, X_OK))
		{
			free(comb_path);
			return (free_arr(path_arr), ft_strdup(path_name));
		}
		if (!access(comb_path, X_OK))
			return (free_arr(path_arr), comb_path);
		free(comb_path);
	}
	return (free_arr(path_arr), ft_strdup(""));
}

void	ft_input_data(char *str, int is_file)
{
	int		fds[2];

	if (is_file)
	{
		fds[0] = open(str, O_RDONLY);
		if (fds[0] == -1)
		{
			perror("opening file error");
			return ;
		}
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	else
	{
		if (pipe(fds))
		{
			perror("pipe error");
			return ;
		}
		write(fds[1], str, ft_strlen(str));
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
}

char	*ft_read_file(int fd)
{
	char	*line;
	char	*str;

	str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		str = ft_free_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str  = ft_strjoin(s1, s2);
	if (!str)
		return (ft_strdup(""));
	free(s1);
	return (str);
}
