/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 01:28:15 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/03 03:14:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_select.h>
#include <libft.h>

/*
** This file containnig a modded version of get_next_line for get a full command
** with cannonical implementation and parsing for the signalslike '^L'
*/

int			input_read(char **line)
{
	int		ret;
	char	*tmp;

	if (line == NULL)
		return (-1);
	else if (ret == 0)
		*line = ft_strnew(0);
	ret = 4;
	tmp = ft_strnew(4);
	ret = read(0, tmp, 4);
	if (ret == -1)
		return (-1);
	tmp[ret] = '\0';
	input(tmp);
	return (0);
}
