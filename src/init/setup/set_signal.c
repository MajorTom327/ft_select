/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:48:05 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 01:05:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <termios.h>

int	sign_handler(int sig)
{
	t_termios term;

	dbg_info("sign_handler", "Received a signal...", 2);
	term = save_term(term, 0);
	tcsetattr(0, TCSANOW, &term);
	exit(0);
}

int	set_signal(void)
{
	int i;

	i = 0;
	while (i < 20)
	{
		signal(i, sign_handler);
		i++;
	}
	return (0);
}