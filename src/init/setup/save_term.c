/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:57:10 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 02:38:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_select.h>
#include <libft.h>

t_termios	save_term(t_termios term, int status)
{
	static t_termios	*m_term = NULL;

	if (status)
	{
		ft_memdel((void **)&m_term);
		m_term = (t_termios *)ft_memalloc(sizeof(t_termios));
		ft_memcpy(m_term, &term, sizeof(t_termios));
	}
	return (*m_term);
}
