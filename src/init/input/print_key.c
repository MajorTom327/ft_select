/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:52:38 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 10:36:39 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <key.h>
#include <libft.h>
#include <ft_select.h>
#include <stdio.h>

int	print_key(t_key *k)
{
	t_key	*tmp;

	tmp = k;
	int i = 0;
	printf("╔═══════════════════════════════╦════════════════════════════╦═════════════════════════════╦════════════════════════╦═══════════════════════════╗\n");
	while (tmp)
	{
		if (i)
			printf("╠═══════════════════════════════╬════════════════════════════╬═════════════════════════════╬════════════════════════╬═══════════════════════════╢\n");
		else
			i = 1;
		printf("║    adresse: %-14p    ║    next: %-14p    ║    value: %-14p    ║    text: %-10s    ║     status: 0x%-8.8x    ║\n", (void *)tmp, (void *)tmp->next, (void *)tmp->value, tmp->value, tmp->status);
		//ft_putendl(tmp->value);
		tmp = tmp->next;
	}
	printf("╚═══════════════════════════════╩════════════════════════════╩═════════════════════════════╩════════════════════════╩═══════════════════════════╝\n");
	return (0);
}
