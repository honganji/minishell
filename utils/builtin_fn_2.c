/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:18:51 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:12:18 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	free_arr(char **path_arr)
{
	int	i;

	i = 0;
	while (path_arr[i])
		free(path_arr[i++]);
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
