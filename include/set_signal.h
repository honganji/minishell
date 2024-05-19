/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:47:09 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 21:40:47 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_SIGNAL_H
# define SET_SIGNAL_H

# include "minishell.h"

void    ft_ctrl_c(int sig);
void    ft_ctrl_bs(int sig);
void	set_signal_fn(void);

#endif