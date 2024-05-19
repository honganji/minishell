/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 22:10:10 by ytoshihi         ###   ########.fr       */
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
    (void)sig;
	set_sig(255);
    printf("\nminishell: ");
    rl_redisplay();
}

/**
 * @brief Function for signal ctrl-backslash
 * 
 * @param sig signal
 * @return void
 */
static void    ft_ctrl_bs(int sig)
{
    (void)sig;
    printf("\nminishell: ");
    rl_redisplay();
	set_sig(255);
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
	signal(SIGQUIT, ft_ctrl_bs);
}
