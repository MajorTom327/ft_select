/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:14:11 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 02:58:21 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_select.h>
#include <term.h>
#include <termios.h>

int	main(int ac, char **av, char **environ)
{
	char	buf[5];
	int		ret;
	t_env	*env;

	dbg_title("init start");
	if ((env = s_init(environ)) == NULL)
		return (-1);
	dbg_title("init end");
	//buf = NULL;
	dbg_title("While start");
	dbg_var_str("main", "term_name", env->term_name, 1);
	while (1)
	{
//		ret = read(0, buf, 4);
//		buf[ret] = '\0';
//		if (buf[0] == 4)
//			sign_handler(0);
		//input_read(&buf);
		//ft_strdel(&buf);
	}
	return (0);
}
