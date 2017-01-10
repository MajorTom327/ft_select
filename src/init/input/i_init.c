/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:26:13 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/10 10:33:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <get_next_line.h>
#include <libft.h>

int	i_init(void)
{
	int		ret;
	char	*buf;

	while ((ret = get_next_line(0, &buf)) > 0)
	{
		//ret = get_next_line(0, &buf);
		dbg_var_str("i_init", "buf", buf, 2);
		ft_strdel(&buf);
	}
}
