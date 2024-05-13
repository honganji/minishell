/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 15:20:49 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

void	ft_output_red(char *name, char *content, int is_append)
{
	int	fd;

	open(name, O_CREAT, 0744);
	if (is_append)
		fd = open(name, O_WRONLY);
	else
		fd = open(name, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("opening file error");
		return ;
	}
	write(fd, content, ft_strlen(content));
	close(fd);
}

// int	main(void)
// {
// 	ft_output_red("text_1.txt", "Hello World!", 1);
// 	ft_output_red("text_2.txt", "Hello World!", 0);
// 	ft_input_data("text_2.txt", 1);
// 	ft_execve("/sort");
// 	printf("\n");
// 	ft_input_data("Hello\nYou\nKing\n", 0);
// 	ft_execve("/sort");
// 	return (0);
// }

// int main() {
//     int pipe_fd[2];  // Array for pipe file descriptors (write, read)
//     pipe(pipe_fd);  // Create the pipe

//     // Prepare arguments for programs (replace with actual commands)
//     char *prog1_argv[] = {"/bin/echo king", NULL};
//     // char *prog2_argv[] = {"/bin/echo king", NULL};

//     // Redirect stdout of program1 to write end of pipe
//     // dup2(pipe_fd[1], STDOUT_FILENO);  // Duplicate write end to stdout

//     // Launch program1
//     execve("/bin/ls", prog1_argv, NULL);
// 	printf("come here\n");
//     perror("execve program1");

//     // Close unused write end (optional)
//     close(pipe_fd[1]);

//     // (Code for program2, potentially using pipe_fd[0] for stdin)
//     // ...

//     return 0;  // Only reached if execve fails
// }

int main() {
    int file_desc = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_desc < 0) {
        perror("open");
        return 1;
    }

    // Redirect stdout to the file
    if (dup2(file_desc, STDOUT_FILENO) < 0) {
        perror("dup2");
        return 1;
    }

    char *argv[] = {"/bin/ls", NULL};
    execve("/bin/ls", argv, NULL);

    // Only reaches here if execve fails
    perror("execve");
    return 1;
}
