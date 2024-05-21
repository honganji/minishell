#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Pomocnicza funkcja do obliczania długości ciągu znaków
static int	get_strlen(char const *str)
{
	int	count = 0;
	while (str[count])
		count++;
	return count;
}

// Funkcja do łączenia dwóch ciągów znaków
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count = 0;

	str = (char *)malloc((get_strlen(s1) + get_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return NULL;
	while (*s1)
		str[count++] = *s1++;
	while (*s2)
		str[count++] = *s2++;
	str[count] = '\0';
	return str;
}

// Funkcja do liczenia backslashy
int	count_backslashes(char **str)
{
	int	count = 0;
	while (**str == '\\')
	{
		count++;
		(*str)++;
	}
	return count;
}

void	print_string(char *str)
{
	int	b;

	while (*str)
	{
		if (*str == '\\')
		{
			b = count_backslashes(&str);
			while (b > 0)
			{
				write(1, "\\", 1);
				b--;
			}
			if (*str == '\0')
				break ;
			write(1, str, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

void	ft_echo(char **args)
{
	char	*str;
	int		i = 1;
	int		newline = 1;

	if (args[i] == NULL)
	{
		write(1, "\n", 1);
		return;
	}
	if (!strncmp(args[i], "-n", 2))
	{
		newline = 0;
		args[i] = ft_strjoin(args[i], "\n");
		i++;
	}
	while (args[i])
	{
		print_string(args[i]);
		if (args[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	// ft_input_data(data, args[i], 0);
}

int main(int argc, char **args) {
	ft_echo(args);
	// printf("All tests passed!\n");
	return 0;
}
