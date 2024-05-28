#include "../include/execution.h"
#include <ctype.h> // Include for isdigit function

// void	ft_export(t_data *data)
// {
// 	char	**env_arr;
// 	t_env	*env_json;
// 	t_list	*targ_lst;
// 	char	*arg;
// 	char	*equal_sign_pos;

// 	if (!((t_cmd *)data->cmd_lst->content)->args[1])
// 		return ;
// 	arg = ((t_cmd *)data->cmd_lst->content)->args[1];
// 	equal_sign_pos = strchr(arg, '=');
// 	if (!equal_sign_pos)
// 		return ; // Return if there's no '=' in the argument
// 	env_arr = (char **)ft_calloc(2, sizeof(char *));
// 	env_json = (t_env *)malloc(sizeof(t_env));
// 	if (!env_arr || !env_json)
// 		critical_err(strerror(errno));
// 	ft_to_json(env_arr, arg);
// 	env_json->key = env_arr[0];
// 	if (isdigit(*env_json->key))
// 	{
// 		syntax_err(data, "export: not a valid identifier: ", env_json->key, 1);
// 		free(env_arr);
// 		free(env_json);
// 		return ;
// 	}
// 	env_json->value = env_arr[1];
// 	targ_lst = ft_find_ele(data, env_json->key);
// 	if (targ_lst)
// 	{
// 		free((*(t_env *)targ_lst->content).key);
// 		free((*(t_env *)targ_lst->content).value);
// 		(*(t_env *)targ_lst->content).key = env_json->key;
// 		(*(t_env *)targ_lst->content).value = env_json->value;
// 		free(env_json);
// 	}
// 	else
// 		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
// 	free(env_arr);
// 	ft_input_data(data, "", 0);
// 	data->exit_code = 0;
// }

void	ft_export(t_data *data)
{
	char	**env_arr;
	t_env	*env_json;
	t_list	*targ_lst;
	char	*arg;

	env_arr = (char **)ft_calloc(1, sizeof(char *));
	env_json = (t_env *)malloc(1 * sizeof(t_env));
	if (!env_arr || !env_json)
		critical_err(strerror(errno));
	arg = ((t_cmd *)data->cmd_lst->content)->args[1];
	if (!arg)
		return ;
	if (!ft_strchr(arg, '='))
	{
		syntax_err(data, "export: no assigning: ", arg, 1); //TODO remove (only debug)
		free(env_arr);
		free(env_json);
		return ;
	}
	ft_to_json(env_arr, arg);
	env_json->key = env_arr[0];
	if (ft_isdigit(*env_json->key))
	{
		syntax_err(data, "export: not a valid identifier: ", env_json->key, 1);
		free(env_arr);
		free(env_json);
		return ;
	}
	env_json->value = env_arr[1];
	targ_lst = ft_find_ele(data, env_arr[0]);
	if (targ_lst)
	{
		free((*(t_env *)targ_lst->content).key);
		free((*(t_env *)targ_lst->content).value);
		(*(t_env *)targ_lst->content).key = env_json->key;
		(*(t_env *)targ_lst->content).value = env_json->value;
	}
	else
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
}



int main(void)
{
	t_data data;
	t_cmd cmd;
	char *args[] = {"export", "KEY", NULL};

	// Initialize data and cmd
	data.cmd_lst = NULL;
	data.env_lst = NULL;
	cmd.args = args;

	// Add cmd to data's command list
	ft_lstadd_back(&data.cmd_lst, ft_lstnew(&cmd));

	// Call ft_export
	ft_export(&data);

	// TODO: Add code to clean up data and cmd if necessary

	return 0;
}
