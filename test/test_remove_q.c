#include <stdio.h>
#include <string.h>

void	rv_quotes(char *str)
{
	int start;
	int end;
	int j;

	j = 0;
	start = 0;
	end = strlen(str) - 1;
	if (!str)
		return ;
	if (str[start] == '\'' || str[start] == '\"')
		start++;
	if (str[end] == '\'' || str[end] == '\"')
		end--;
	while (start <= end)
		str[j++] = str[start++];
	str[j] = '\0';
}

int	main(void)
{
	char	str[] = "\"   adfsagd' dsfas' gs\"adsg asg'fadf af\"\"";

	printf("rv_quotes: %s\n", str);
	rv_quotes(str);
	printf("rv_quotes: %s\n", str);

	// printf("remove_outer_quotes: %s\n", str);
	// remove_outer_quotes(str);
	// printf("remove_outer_quotes: %s\n", str);
	return (0);
}
