/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:52:38 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/10 10:56:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <key.h>
#include <libft.h>

int	print_key(t_key *k)
{
	ft_putendl("\033[34m[   START   ]\033[0m");
	while (k)
	{
		ft_putendl(k->value);
		k = k->next;
	}
	ft_putendl("\033[34m[    END    ]\033[0m");
	return (0);
}
