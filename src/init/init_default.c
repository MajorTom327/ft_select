/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:25:44 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 04:20:40 by vthomas          ###   ########.fr       */
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
	char	*cmd;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "TERM=", 5) == 0)
			break;
		i++;
	}
	if (environ[i] == NULL)
	{
		ft_putendl_fd("An error occured ! The env var \"TERM\" isn't set !", 2);
		exit(-1);
	}
	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->term_name = ft_strdup(&(environ[i][5]));
	if (tgetent(NULL, env->term_name) <= 0)
		exit(-1);
	tcgetattr(0, &(env->termios));
	env->termios.c_lflag &= ECHOKE | ECHO;
	env->termios.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &(env->termios));
	cmd = tgetstr("vi", NULL);
	if (cmd != NULL)
		tputs(cmd, 0, ft_putchar);
}
