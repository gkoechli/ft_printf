/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:33:49 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/22 16:25:05 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_translate(const char *str, int i, int sign)
{
	int	tmp;

	tmp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + ((int)str[i] - 48);
		i++;
	}
	if (sign == 1)
		return (tmp * -1);
	return (tmp);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		return (ft_translate(str, i, sign));
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (0);
}

void	ft_precichar(t_list *d, t_flags *f)
{
	if (f->preci == 0 && d->c != 's' && d->c != 'c' && d->c != 'p')
	{
		if (ft_strncmp(d->bis, "0\0", 2) == 0)
		{
			free (d->bis);
			d->bis = NULL;
			d->bislen = 0;
			return ;
		}
	}
	if (d->bis != 0 && d->sign == 1 && d->bislen <= f->preci)
		d->bis[0] = '0';
	return ;
}
