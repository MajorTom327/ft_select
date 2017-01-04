/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:06:54 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/04 00:24:16 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>

t_env	*s_init(char **environ)
{
	t_env	*env;
	int		i;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "TERM=", 5) == 0)
		{
			env->term_name = ft_strdup(&environ[i][5]);
			break;
		}
		i++;
	}
	if (environ[i] == NULL)
		return (NULL);
	return (set_option(env));
}
