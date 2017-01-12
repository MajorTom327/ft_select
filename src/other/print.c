/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:17:45 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 12:46:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <key.h>

#include <libft.h>

#include <termios.h>
#include <term.h>

int	print(t_key *k)
{
	t_key *cur;

	cur = k;
	ft_tcstr("cl");
	while (cur)
	{
		if (cur->status & F_SELECTED)
			ft_tcstr("mr");
		if (cur->status & F_CURSOR)
			ft_tcstr("us");
		ft_putendl(cur->value);
		if (cur->status & F_SELECTED)
			ft_tcstr("me");
		cur = cur->next;
	}
}
