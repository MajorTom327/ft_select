/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:26:13 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/10 11:03:04 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <get_next_line.h>
#include <libft.h>
#include <key.h>

t_key	*i_init(void)
{
	int		ret;
	char	*buf;
	t_key	*k;
	t_key	*current;
	t_key	*old;

	k = (t_key *)ft_memalloc(sizeof(t_key));
	current = k;
	while ((ret = get_next_line(0, &buf)) > 0)
	{
		dbg_var_str("i_init", "buf", buf, 2);
		//current->next = (t_key *)ft_memalloc(sizeof(t_key));
		dbg_var_str("i_init", "buf", buf, 2);
		//current = current->next;
		dbg_var_str("i_init", "buf", buf, 2);
		current->value = ft_strdup("");
		dbg_var_str("i_init", "buf", buf, 2);
		ft_strdel(&buf);
	}
	old = k;
	k = k->next;
	ft_strdel(&(old->value));
	ft_memdel((void **)&old);
	return (k);
}
