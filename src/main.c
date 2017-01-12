/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:14:11 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 14:13:47 by vthomas          ###   ########.fr       */
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
	if ((env = s_init(environ)) == NULL)
		return (-1);
	env->k = k;
	env->k->status = F_CURSOR;
	print_key(env->k);
	//move(env, VK_UP);
	dbg_var_str("main", "term_name", env->term_name, 1);
	print(env->k);
	while (1)
	{
		ret = read(0, buf, 3);
		buf[ret] = '\0';
		if (buf[0] == 4)
			print_key(env->k);
		if (ret)
		{
			if (buf[0] == 27)
				move(env, buf[2]);
			print(env->k);
		}
		//print(k);
		//input_read(&buf);
		//ft_strdel(&buf);
	}
	return (0);
}
