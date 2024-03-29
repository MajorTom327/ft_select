/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:36:02 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 10:33:43 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H
# define F_NONE		0x00
# define F_SELECTED	0x01
# define F_CURSOR	0x02

typedef struct	s_key
{
	char			*value;
	int				status;
	struct s_key	*next;
}				t_key;

#endif
