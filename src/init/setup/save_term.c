/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:57:10 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 01:03:11 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_select.h>

t_termios	save_term(t_termios term, int status)
{
	static t_termios	m_term;

	if (status)
		m_term = term;
	return (m_term);
}
