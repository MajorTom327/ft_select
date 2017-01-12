/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 14:14:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <key.h>

int	move(t_env *env, int dir)
{
	int		i;
	t_key	*key;

	i = 0;
	key = env->k;
	dbg_var_int("move", "env->pos", env->pos, 3);
	while (i < env->pos)
	{
		key = key->next;
		i++;
	}
	if (dir == VK_UP)//go up
	{
		if (i < 0)
			return (0);
		if (i != 0)
			env->pos--;
		key->status = key->status | F_CURSOR;
		if (key->next)
			key->next->status = key->next->status & ~(F_CURSOR);
	}
	else if (dir == VK_DOWN)
	{
		if (key->next == NULL)
			return (1);
		env->pos++;
		key->status = key->status & ~(F_CURSOR);
		key->next->status = key->next->status | F_CURSOR;
	}
	dbg_var_int("move", "env->pos", env->pos, 3);
	return (0);
}
