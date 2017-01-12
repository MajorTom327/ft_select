/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:26:13 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 10:08:32 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

#include <libft.h>
#include <key.h>

t_key	*i_init(void)
{
	t_key	*key;
	t_key	*tmp;
	t_key	*last;
	char	*buf;
	int		ret;

	key = (t_key *)ft_memalloc(sizeof(t_key));
	tmp = key;
	ret = 0;
	buf = NULL;
	while ((ret = get_next_line(0, &buf)) > 0)
	{
		last = tmp;
		tmp->next = NULL;
		tmp->value = ft_strdup(buf);
		tmp->next = (t_key *)ft_memalloc(sizeof(t_key));
		tmp->status = 0;
		tmp = tmp->next;
		ft_strdel(&buf);
	}
	ft_strdel(&buf);
	last->next = NULL;
	ft_memdel(&tmp);
	return (key);
}
