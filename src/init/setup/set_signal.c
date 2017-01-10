/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:48:05 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/10 08:06:26 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>

#include <termios.h>
#include <term.h>

#include <stdlib.h>
#include <signal.h>

void	sign_handler(int sig)
{
	char	*str;

	dbg_info("sign_handler", "Received a signal...", 2);
	str = tgetstr("ve", NULL);
	tputs(str, 0, output);
	exit(0);
}

int		set_signal(void)
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
