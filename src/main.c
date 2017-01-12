/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:14:11 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 11:10:26 by vthomas          ###   ########.fr       */
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
	t_key	*k;

	k = i_init();
	print_key(k);
	if ((env = s_init(environ)) == NULL)
		return (-1);
	dbg_var_str("main", "term_name", env->term_name, 1);
	print(k);
	while (1)
	{
		ret = read(0, buf, 3);
		buf[ret] = '\0';
		if (buf[0] == 4)
			sign_handler(0);
		if (buf[0] != 0)
		{
			dbg_var_int("main", "buf[0]", buf[0], 2);
			dbg_var_int("main", "buf[1]", buf[1], 2);
			dbg_var_int("main", "buf[2]", buf[2], 2);
		}
		//print(k);
		//input_read(&buf);
		//ft_strdel(&buf);
	}
	return (0);
}
