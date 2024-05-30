#include "./include/utils.h"



char	first_quote(char *str)
{
	while (*str)
	{
		if (*str == '"' || *str == '\'')
			return (*str);
		str++;
	}
	return (0);
}

size_t	no_quotes_strlen(char *str, char start_quote)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str != start_quote)
			len++;
		str++;
	}
	return (len);
}

char	*remove_quotes(char *str)
{
	int		i;
	char	start_quote;
	char	*new_str;
	size_t	no_quotes_len;
	int		j;

	i = 0;
	j = 0;
	start_quote = first_quote(str);
	no_quotes_len = no_quotes_strlen(str, start_quote);
	new_str = (char *)calloc(no_quotes_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != start_quote)
			new_str[j++] = str[i];
		i++;
	}
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
	char	str9[] = "hello'world'";
	char	str10[] = "hello\"\"world";
	char	*result1;
	char	*result2;
	char	*result3;
	char	*result4;
	char	*result5;
	char	*result6;
	char	*result7;
	char	*result8;
	char	*result9;
	char	*result10;

	result1 = remove_quotes(str1);
	result2 = remove_quotes(str2);
	result3 = remove_quotes(str3);
	result4 = remove_quotes(str4);
	result5 = remove_quotes(str5);
	result6 = remove_quotes(str6);
	result7 = remove_quotes(str7);
	result8 = remove_quotes(str8);
	result9 = remove_quotes(str9);
	result10 = remove_quotes(str10);

	printf("Input: %s\n", str1);     // Input: "asdf"
	printf("Output: %s\n", result1); // Output: asdf
	printf("Correct output: asdf\n\n");
	printf("Input: %s\n", str2);     // Input: "fsdf'
	printf("Output: %s\n", result2); // Output: fsdf'
	printf("Correct output: fsdf'\n\n");
	printf("Input: %s\n", str3);     // Input: fsd"fdsf"fd
	printf("Output: %s\n", result3); // Output: fsdfdsf
	printf("Correct output: fsdfdsf\n\n");
	printf("Input: %s\n", str4);     // Input: 'quote'
	printf("Output: %s\n", result4); // Output: quote
	printf("Correct output: quote\n\n");
	printf("Input: %s\n", str5);     // Input: "fsdsaf"fdsf"fdsdf"
	printf("Output: %s\n", result5); // Output: fsdsaffdsffdsdf
	printf("Correct output: fsdsaffdsffdsdf\n\n");
	printf("Input: %s\n", str6);     // Input: "fds'fds'"
	printf("Output: %s\n", result6); // Output: fds'fds'
	printf("Correct output: fds'fds'\n\n");
	printf("Input: %s\n", str7);     // Input: 'fdasfdsa"fdasf"fasfda'
	printf("Output: %s\n", result7); // Output: fdasfdsafdafasfda
	printf("Correct output: fdasfdsafdafasfda\n\n");
	printf("Input: %s\n", str8);     // Input: 'fasdf'fdasf'fasdf'
	printf("Output: %s\n", result8); // Output: fasdffdasffasdf
	printf("Correct output: fasdffdasffasdf\n\n");
	printf("Input: %s\n", str9);     // Input: hello'world'
	printf("Output: %s\n", result9); // Output: helloworld
	printf("Correct output: helloworld\n\n");
	printf("Input: %s\n", str10);     // Input: hello""world
	printf("Output: %s\n", result10); // Output: helloworld
	printf("Correct output: helloworld\n\n");
	return (0);
}
