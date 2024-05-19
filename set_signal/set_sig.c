/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 21:19:56 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set_signal.h"

// sig == 2
void    ft_ctrl_c(int sig)
{
    (void)sig;
	set_sig(255);
    printf("\nminishell: ");
    rl_redisplay();
}

// sig == 3
void    ft_ctrl_bs(int sig)
{
    (void)sig;
    printf("\nminishell: ");
    rl_redisplay();
	set_sig(255);
}
