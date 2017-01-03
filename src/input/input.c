/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 05:20:42 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 04:26:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>

#include <termios.h>
#include <term.h>

void	input(char *str)
{
	char *cmd;

	if (str[0] == 12)
	{
		cmd = tgetstr("cl", NULL);
		if (cmd != NULL)
			tputs(cmd, 0, ft_putchar);
		ft_strclr(str);
	}
	else if (str[0] == 4 || str[0] == 3)
	{
		cmd = tgetstr("ve", NULL);
		if (cmd != NULL)
			tputs(cmd, 0, ft_putchar);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(str, "\033[", 2) == 0)
	{
		//MOTION
		if (str[2] == VK_UP)
			dbg_info("input", "up pressed", 1);
		else if (str[2] == VK_LEFT)
			dbg_info("input", "left pressed", 1);
		else if (str[2] == VK_RIGHT)
			dbg_info("input", "right pressed", 1);
		else if (str[2] == VK_DOWN)
			dbg_info("input", "down pressed", 1);
		ft_strclr(str);
	}
}
