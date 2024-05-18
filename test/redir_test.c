# include "../include/minishell.h"

int main(void)
{
	t_token	*token;
	t_data	*data;

	token = malloc(sizeof(t_token));
	if (!token)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	token->type = REDIR;
	token->data = "<<";
	token->next = malloc(sizeof(t_token));
	if (!token->next)
		return (1);
	token->next->type = WORD;
	token->next->data = "file.txt";
	token->next->next = NULL;
	parse_commands(token, data);
	return (0);
}
