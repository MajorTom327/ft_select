/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:26:15 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 02:25:18 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <debug.h>

typedef struct termios	t_termios;

typedef struct	s_env
{
	t_termios	term;
	t_termios	def_term;
	char		*term_name;
}				t_env;

int				output(int c);
int				ft_tcstr(const char *str);

t_termios		save_term(t_termios term, int status);
t_env			*s_init(char **environ);
t_env			*set_option(t_env *env);
int				set_signal(void);
void			sign_handler(int sig);
#endif
