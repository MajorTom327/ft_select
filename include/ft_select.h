/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:26:15 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 03:21:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define VK_UP		65
# define VK_LEFT	68
# define VK_RIGHT	67
# define VK_DOWN	66

# include <termios.h>
# include <debug.h>

typedef struct	s_env
{
	struct termios	termios;
}				t_env;

void	getsetting(void);
t_env	*init_default(char **environ);

int		input_read(char **line);
void	input(char *str);
#endif
