/* ************************************************************************** */
/*	    */
/*	:::      ::::::::   */
/*   set_val.c	  :+:      :+:    :+:   */
/*	    +:+ +:+	 +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>	  +#+  +:+       +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/05/13 19:32:42 by ytoshihi	  #+#    #+#	     */
/*   Updated: 2024/05/16 19:03:18 by ytoshihi	 ###   ########.fr       */
/*	    */
/* ************************************************************************** */

#include "../include/test.h"

/**
 * @brief Create a new cmd struct so that can be stored in data.
 *
 *
 * @param com command enum
 * @param str whole arguments for a command
 * @param input input file name or 
 * @param str The command to execute.
 * @return void
 * 
 */
static t_cmd *create_cmd(t_com com, char *str, t_redir input, t_redir output)
{
    // store commands
	t_cmd *content;

    content = ft_calloc(1, sizeof(t_cmd));
    content->com = com;
    content->args = ft_split(str, ' ');
    content->input = input;
    content->output = output;
    return (content);
}

void	set_val(t_data *data, char **env)
{
    t_list  *tmp;
	t_cmd   *content;

    content = create_cmd(ECHO, "echo king", (t_redir){.is_single = 1, .file_name="text_1.txt"}, (t_redir){.is_single = 1, .file_name="output_1.txt"});
    ft_lstadd_back(&data->cmd_lst, ft_lstnew(content));
    // content = create_cmd(CD, "cd ..", (t_redir){.is_single = 1, .file_name="text_2.txt"}, (t_redir){.is_single = 1, .file_name="output_2.txt"});
    // ft_lstadd_back(&data->cmd_lst, ft_lstnew(content));
    content = create_cmd(PWD, "pwd", (t_redir){.is_single = 1, .file_name="text_3.txt"}, (t_redir){.is_single = 1, .file_name="output_3.txt"});
    ft_lstadd_back(&data->cmd_lst, ft_lstnew(content));
    content = create_cmd(ETC, "sort", (t_redir){.is_single = 1, .file_name=NULL}, (t_redir){.is_single = 1, .file_name=NULL});
    ft_lstadd_back(&data->cmd_lst, ft_lstnew(content));
    tmp = data->cmd_lst;
	while (tmp)
	{
		printf("command:\n");
		printf("cmd: %d\n", ((t_cmd *)tmp->content)->com);
		printf("args: %s\n", ((t_cmd *)tmp->content)->args[0]);
		printf("input: %s\n", ((t_cmd *)tmp->content)->input.file_name);
		printf("output: %s\n\n", ((t_cmd *)tmp->content)->output.file_name);
		tmp = tmp->next;
    }
	// get env variables
	ft_store_env(data, env);
}
