/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:22:51 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 01:06:59 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>
#include <termios.h>

t_env	*set_option(t_env *env)
{
	if (tgetent(NULL, env->term_name) <= 0)
		return (NULL);
	tcgetattr(0, &(env->def_term));
	env->term = env->def_term;
	env->term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &(env->term));
	save_term(env->term, 1);
	set_signal();
	return (env);
}
