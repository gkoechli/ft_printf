/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:06:06 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/13 15:37:37 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(size_t n, long s)
{
	int	i;

	i = 1;
	while ((n / s) > 0)
	{
		i++;
		n = n / s;
	}
	return (i);
}

void	ft_fill(long u, t_list *d, int intlen, char *s)
{
	long int	n;

	n = ft_strlen(s);
	if (u < 0)
	{
		u = (u * -1);
		d->sign = 1;
	}
	intlen = ft_intlen(u, n) + d->sign;
	if (d->c == 'p')
		intlen += 2;
	d->bis = malloc(sizeof(char) * intlen + 1);
	d->bislen = intlen;
	if (d->bis == NULL)
		return ;
	d->bis[intlen] = '\0';
	while (intlen > 0)
	{
		d->bis[--intlen] = s[u % n];
		u = u / n;
	}
	return ;
}

void	ft_fillp(unsigned long u, t_list *d, int intlen, char *s)
{
	unsigned int	n;

	n = ft_strlen(s);
	intlen = ft_intlen(u, n) + d->sign;
	if (d->c == 'p')
		intlen += 2;
	d->bis = malloc(sizeof(char) * intlen + 1);
	d->bislen = intlen;
	if (d->bis == NULL)
		return ;
	d->bis[intlen] = '\0';
	while (intlen > 0)
	{
		d->bis[--intlen] = s[u % n];
		u = u / n;
	}
	return ;
}

void	ft_baseconv(size_t n, char *s, t_list *d, char c)
{
	int		intlen;

	intlen = 0;
	d->sign = 0;
	d->c = c;
	if (d->c == 'p')
		ft_fillp(n, d, intlen, s);
	else
		ft_fill(n, d, intlen, s);
	if (d->c == 'p')
	{
		d->bis[0] = '0';
		d->bis[1] = 'x';
	}
	if (d->sign == 1)
		d->bis[intlen] = '-';
	return ;
}
