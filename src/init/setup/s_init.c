/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 00:06:54 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/12 12:52:32 by vthomas          ###   ########.fr       */
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
	dbg_info("s_init", "malloc env", 2);
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "TERM=", 5) == 0)
		{
			env->term_name = ft_strdup(&environ[i][5]);
			break;
		}
		i++;
	}
	dbg_var_str("s_init", "terminal definition found", env->term_name, 2);
	if (environ[i] == NULL)
		return (NULL);
		env->pos = 0;
	return (set_option(env));
}
