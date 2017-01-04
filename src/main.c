/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:14:11 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 02:08:02 by vthomas          ###   ########.fr       */
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
	t_env	*env;

	dbg_title("init start");
	env = s_init(environ);
	dbg_title("init end");
	buf = NULL;
	dbg_title("While start");
	dbg_var_str("main", "term_name", env->term_name, 1);
	while (1)
	{
		//input_read(&buf);
		sleep(10000);
		ft_strdel(&buf);
	}
	return (0);
}
