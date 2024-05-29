#include "./include/utils.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		in_quotes;
	char	start_quote;
	char	*new_str;
    int		j;

	i = 0;
	j = 0;
	in_quotes = 0;
	start_quote = 0;
	new_str = (char *)malloc((strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			start_quote = str[i];
			break ;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			in_quotes = 1;
			while (str[i] && str[i] != start_quote)
			{
				new_str[j] = str[i];
				j++;
				i++;
			}
			if (!str[i])
				break ;
			if (str[i] == start_quote && in_quotes == 1)
			{
				i++;
				in_quotes = 0;
			}
			else
				new_str[j] = str[i];
			j++;
		}
		else
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	main(void)
{
	char	str1[] = "\"asdf\"";
	char	str2[] = "\"fsdf'";
	char	str3[] = "fsd\"fdsf\"fd";
	char	str4[] = "'quote'";
	char	str5[] = "\"fsdsaf\"fdsf\"fdsdf\"";
	char	str6[] = "\"fds'fds'\"";
	char	str7[] = "'fdasfdsa\"fdasf\"fasfda'";
	char	str8[] = "'fasdf'fdasf'fasdf'";
	char	*result1;
	char	*result2;
	char	*result3;
	char	*result4;
	char	*result5;
	char	*result6;
	char	*result7;
	char	*result8;

	result1 = remove_quotes(str1);
	result2 = remove_quotes(str2);
	result3 = remove_quotes(str3);
	result4 = remove_quotes(str4);
	result5 = remove_quotes(str5);
	result6 = remove_quotes(str6);
	result7 = remove_quotes(str7);
	result8 = remove_quotes(str8);
	printf("Output: %s\n", result1); // Output: asdf
	printf("Output: %s\n", result2); // Output: fsdf'
	printf("Output: %s\n", result3); // Output: fsdfdsf
	printf("Output: %s\n", result4); // Output: quote
	printf("Output: %s\n", result5); // Output: fsdsaffdsffdsdf
	printf("Output: %s\n", result6); // Output: fds'fds'
	printf("Output: %s\n", result7); // Output: fdasfdsafdafasfda
	printf("Output: %s\n", result8); // Output:
	return (0);
}
