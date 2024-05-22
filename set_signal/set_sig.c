/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuji <yuji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 08:35:52 by yuji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set_signal.h"

/**
 * @brief Function for signal ctrl-c
 * 
 * @param sig signal
 * @return void
 */
static void    ft_ctrl_c(int sig)
{
    struct termios term;

    if ((term.c_lflag & ICANON))
    {
        printf("\nminishell: ");
        rl_redisplay();
    }
	set_sig(sig);
    term.c_lflag |= ECHO;
}

/**
 * @brief Function for signal ctrl-backslash
 * 
 * @param sig signal
 * @return void
 */
static void    ft_ctrl_bs(int sig)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    if (term.c_lflag & ICANON)
    {
        printf("\nminishell: ");
        rl_redisplay();
    }
	set_sig(sig);
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
	signal(SIGQUIT, ft_ctrl_bs);
}
