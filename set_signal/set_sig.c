/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 14:27:49 by ytoshihi         ###   ########.fr       */
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
	// TODO uncomment
	// struct termios	term;

	// if ((term.c_lflag & ICANON))
	// {
	// 	printf("\nminishell: ");
	// 	rl_redisplay();
	// }
	set_sig(sig);
	// TODO remove
	printf("\nminishell: ");
	rl_redisplay();
	// term.c_lflag |= ECHO;
}

/**
 * @brief Set function for signals
 * 
 * @return void
 */
void	set_signal_fn(void)
{
	// TODO uncomment
	// rl_catch_signals = 0;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
