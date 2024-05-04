/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:24:36 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 22:58:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_del_node(t_data *data, t_list *lst, t_list *pre_lst)
{
	if (!pre_lst)
	{
		data->env_lst = data->env_lst->next;
		free(((t_env *)(lst->content))->key);
		free(((t_env *)(lst->content))->value);
		free(lst->content);
		free(lst);
		return ;
	}
	else
	{
		pre_lst->next = lst->next;
		free(((t_env *)(lst->content))->key);
		free(((t_env *)(lst->content))->value);
		free(lst->content);
		free(lst);
		return ;
	}
}

t_list	*ft_find_ele(t_data *data, char *str)
{
	char	*key;
	t_list	*tmp;

	tmp = data->env_lst;
	while (tmp)
	{
		key = (*(t_env *)(tmp->content)).key;
		if (!ft_strncmp(key, str, ft_strlen(key)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static int	ft_count_arg(t_data *data, char *str)
{
	int		count;
	t_list	*tmp;

	count = 0;
	while (*str)
	{
		if (*str++ == '$')
		{
			tmp = ft_find_ele(data, str);
			if (tmp)
			{
				count--;
				count += ft_strlen((*(t_env *)tmp->content).value);
				str += ft_strlen((*(t_env *)tmp->content).key);
			}
		}
		count++;
	}
	return (count);
}

char	*ft_rep_env(t_data *data, char *str)
{
	int		i;
	char	*arg;
	t_list	*tmp;

	i = 0;
	arg = (char *)ft_calloc(ft_count_arg(data, str) + 1, sizeof(char));
	while (*str)
	{
		arg[i] = *str;
		if (*str++ == '$')
		{
			tmp = ft_find_ele(data, str);
			if (tmp)
			{
				ft_strlcpy(&arg[i], (*(t_env *)tmp->content).value,
					ft_strlen((*(t_env *)tmp->content).value) + 1);
				i += ft_strlen((*(t_env *)tmp->content).value);
				str += ft_strlen((*(t_env *)tmp->content).key);
				i--;
			}
		}
		i++;
	}
	arg[i] = '\0';
	return (arg);
}

void	ft_to_json(char **env_json, char *env_name)
{
	int	count;

	count = 0;
	while (env_name[count] != '=' && env_name[count])
		count++;
	env_json[0] = ft_substr(env_name, 0, count);
	env_json[1] = ft_substr(env_name, count + 1, ft_strlen(env_name) - count);
}
