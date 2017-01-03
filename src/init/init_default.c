/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:25:44 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 03:21:52 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <termios.h>
#include <term.h>

#include <ft_select.h>
#include <libft.h>

t_env	*init_default(char **environ)
{
	t_env	*env;
	int		i;
	char	*term;

	i = 0;
	dbg_title("Start search");
	while (environ[i])
	{
		dbg_var_str("init_default", "current env", environ[i], 1);
		if (ft_strncmp(environ[i], "TERM=", 5) == 0)
			break;
		i++;
	}
	dbg_var_int("init_default", "environ term", i, 1);
	if (environ[i] == NULL)
		exit(-1);
	term = &(environ[i][5]);
	dbg_var_str("init_default", "term name", term, 1);
	if (tgetent(NULL, term) == -1)
		exit(-1);
	dbg_info("init_default", "tgetent", 2);
	env = (t_env *)ft_memalloc(sizeof(t_env));
	tcgetattr(0, &(env->termios));
	env->termios.c_lflag &= ECHOKE | ECHO;
	env->termios.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &(env->termios));
}
