/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:08:30 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 02:26:32 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>

int	output(int c)
{
	write(1, (char *)&c, 1);
	return (0);
}

int	ft_tcstr(const char *str)
{
	char *cmd;

	cmd = tgetstr((char *)str, NULL);
	if (cmd == NULL)
		return (-1);
	tputs(cmd, 0, output);
	return (0);
}
