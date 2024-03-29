/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:26:15 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 14:28:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <debug.h>
# include <key.h>

# define VK_UP		65
# define VK_DOWN	66

typedef struct termios	t_termios;

typedef struct	s_env
{
	t_termios	term;
	t_termios	def_term;
	char		*term_name;
	t_key		*k;
	int			pos;
}				t_env;

int				output(int c);
int				ft_tcstr(const char *str);
int				print(t_key *k);

int				print_key(t_key *k);
int				move(t_env *env, int dir);
int				select_switch(t_env *env);

t_key			*i_init(void);

t_termios		save_term(t_termios term, int status);
t_env			*s_init(char **environ);
t_env			*set_option(t_env *env);
int				set_signal(void);
void			sign_handler(int sig);
#endif
