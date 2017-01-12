/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:24:16 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 14:35:23 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>
#include <key.h>

int	select_switch(t_env *env)
{
	t_key	*key;

	key = env->k;
	while (key)
	{
		if (key->status & F_CURSOR)
		{
			//if (key->status & F_SELECTED)
			key->status = (!(key->status & F_SELECTED)) ? key->status | F_SELECTED : key->status & ~(F_SELECTED);
			break;
		}
		key = key->next;
	}
	return (0);
}
