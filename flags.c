/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:55:01 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/22 16:17:46 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_opt(t_list *d, t_flags *f, va_list *ap)
{
	ft_convert(d->c, ap, d);
	if (f->pmodif > 0)
		ft_precision(d, f);
	if (f->zero > 0 && f->pmodif > 0)
	{
		f->field = f->zero;
		f->zero = 0;
	}
	if (f->zero > 0)
	{
		if (d->c == 'i' || d->c == 'd' || d->c == 'u' || d->c == 'x'
			|| d->c == 'X' || d->c == '%')
			ft_zero(d, f);
		else
		{
			f->field = f->zero;
			f->zero = 0;
		}
	}
	if (f->min > 0)
		ft_minus(d, f);
	if (f->field > 0)
		ft_field(d, f);
	d->bslash = 0;
	d->ret += d->bislen;
}

void	ft_precision(t_list *d, t_flags *f)
{
	int	u;
	int	match;

	match = 0;
	u = 0;
	ft_precichar(d, f);
	if (d->bis)
		u = d->bislen;
	if (d->c == 's' && f->preci < u && f->pmodif > 0)
		ft_subsprec(d, f->preci);
	if (u > f->preci)
		return ;
	if (ft_strchr(PRECI, d->c))
	{
		match = 1;
		while (f->preci-- > u)
			add_char_before(d, '0');
	}
	if (d->sign == 1 && match != 1)
		d->bis[0] = '-';
	else if (d->sign == 1)
		add_char_before(d, '-');
	d->sign = 0;
	f->preci = 0;
	return ;
}

void	ft_field(t_list *d, t_flags *f)
{
	int	u;

	u = 0;
	if (d->c == 'c')
	{
		while (f->field-- > d->bislen)
		{
			write(1, " ", 1);
			d->ret++;
		}
	}
	if (d->bis)
		u = d->bislen;
	while (f->field-- > u)
		add_char_before(d, ' ');
	f->field = 0;
	d->sign = 0;
	return ;
}

void	ft_minus(t_list *d, t_flags *f)
{
	int	u;

	u = 0;
	if (d->c == 'c' && d->bslash == 1)
	{
		free(d->bis);
		d->bis = malloc(sizeof(char) * f->min + 1);
		if (d->bis == NULL)
			return ;
		d->bis[u] = '\0';
		while (f->min > ++u)
			d->bis[u] = ' ';
		d->bis[u] = '\0';
		d->bislen = u;
		f->min = 0;
		return ;
	}
	if (d->bis)
		u = d->bislen;
	while (f->min-- > u)
		add_char_after(d, ' ');
	f->min = 0;
	d->sign = 0;
	return ;
}

void	ft_zero(t_list *d, t_flags *f)
{
	int	u;

	u = 0;
	if (d->bis)
		u = ft_strlen(d->bis);
	if (d->sign == 1)
		d->bis[0] = '0';
	while (f->zero-- > u)
		add_char_before(d, '0');
	if (d->sign == 1)
		d->bis[0] = '-';
	f->zero = 0;
	d->sign = 0;
	return ;
}
