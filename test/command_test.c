/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:31:43 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 20:07:20 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	test_1(t_data *data)
{
	char	*value;

	printf("----------------pwd test-----------------------\n");
	ft_exe_command(data, NULL, PWD);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	printf("\n----------------cd test------------------------\n");
	ft_exe_command(data, "execution", CD);
	ft_exe_command(data, NULL, PWD);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	printf("\n");
	printf("----------------env test-----------------------\n");
	ft_exe_command(data, NULL, ENV);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
}

static void	test_2(t_data *data)
{
	char	*value;

	printf("----------------export, and unset test---------\n");
	ft_exe_command(data, "General $GEN1\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	ft_exe_command(data, "GEN1=Nobunaga Oda", EXPORT);
	ft_exe_command(data, "General $GEN1\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	ft_exe_command(data, "GEN2=Hideyoshi Toyotomi", EXPORT);
	ft_exe_command(data, "GEN3=Ieyasu Tokugawa", EXPORT);
	ft_exe_command(data, "GEN1", UNSET);
	ft_exe_command(data, "General $GEN1\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
}

static void	test_3(t_data *data)
{
	char	*value;

	printf("----------------echo test---------------------\n");
	ft_exe_command(data, "\"I am a hero\"\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	printf("----------------export update test------------\n");
	ft_exe_command(data, "General $GEN2\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	ft_exe_command(data, "GEN2=Kintama", EXPORT);
	ft_exe_command(data, "General $GEN2\n", ECHO);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	printf("----------------builtin command test----------\n");
	ft_exe_command(data, "/ls", ETC);
	printf("%s", value = ft_read_file(STDIN_FILENO));
	free(value);
	printf("-----Finish-----------------------------------\n");
}

void	command_test(t_data *data)
{
	test_1(data);
	test_2(data);
	test_3(data);
}
