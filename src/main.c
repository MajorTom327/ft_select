/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:14:11 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 03:35:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_select.h>
#include <term.h>
#include <termios.h>

int	main(int ac, char **av, char **environ)
{
	char	*buf;
	char	*cmd;
	t_env	*env;

	dbg_title("init start");
	env = init_default(environ);
	dbg_title("init end");
	buf = NULL;
	while (1)
	{
		input_read(&buf);
		//get_command(&buf);
		//get_next_line(0, &buf);
		//tputs("bl", 0, NULL);
		cmd = tgetstr("us", NULL);
		if (cmd != NULL)
			tputs(cmd, 0, ft_putchar);
		ft_putstr("Hello World");
		cmd = tgetstr("ue", NULL);
		if (cmd != NULL)
			tputs(cmd, 0, ft_putchar);
		ft_strdel(&buf);
	}
	return (0);
}
