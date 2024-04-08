/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:17:30 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/13 14:54:26 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

void	ft_reset_list(t_list *s)
{
	s->i = 0;
	s->j = 0;
	s->ret = 0;
	s->sign = 0;
	s->match = 0;
	s->c = 0;
	s->bis = 0;
	s->bislen = 0;
	s->bslash = 0;
}

void	ft_reset_flags(t_flags *s)
{
	s->preci = 0;
	s->field = 0;
	s->min = 0;
	s->zero = 0;
	s->num = 0;
	s->pmodif = 0;
}

int	ft_strlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	if (s == NULL)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
