/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/02 10:58:00 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set_signal.h"

/**
 * @brief Function for signal ctrl-c
 * 
 * @param sig signal
 * @return void
 */
static void	ft_ctrl_c(int sig)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	if (!(term.c_lflag & ICANON))
		printf("\nminishell: ");
	else
		printf("\n");
	set_sig(sig);
	rl_redisplay();
}

/**
 * @brief Set function for signals
 * 
 * @return void
 */
void	set_signal_fn(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
