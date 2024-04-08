/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:28:09 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/13 14:52:13 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < size - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_num(const char *s, t_list *d, t_flags *f)
{
	int	u;

	u = 0;
	if (ft_strchr(DECI, s[d->i]))
	{
		while (ft_isdigit(s[d->i + u]))
			u++;
		ft_substrf(s, d, u);
		f->num = ft_atoi(d->bis);
		free (d->bis);
		d->i += u;
	}
	else
		f->num = 0;
	return (f->num);
}

void	ft_zmp(const char *s, t_list *d, t_flags *f)
{
	if (s[d->i] == '0')
	{
		d->i++;
		f->zero = ft_num(s, d, f);
	}
	if (s[d->i] == '-')
	{
		d->i++;
		f->min = ft_num(s, d, f);
	}
	if (s[d->i] == '.')
	{
		d->i++;
		f->preci = ft_num(s, d, f);
		f->pmodif = 1;
	}
	f->num = 0;
	return ;
}

void	ft_flags(const char *s, t_list *d, t_flags *f, va_list *ap)
{
	int	u;

	u = 0;
	d->i++;
	while (is_flag_or_opt(s[d->i]) != 1 && s[d->i])
	{
		if (ft_strchr(NUFLGS, s[d->i]))
		{
			while (ft_isdigit(s[d->i + u]))
				u++;
			ft_substrf(s, d, u);
			f->field = ft_atoi(d->bis);
			free (d->bis);
			d->i += u;
		}
		ft_zmp(s, d, f);
	}
	d->c = s[d->i];
	ft_convert_opt(d, f, ap);
	write(1, d->bis, d->bislen);
	free(d->bis);
	d->j = 0;
	f->pmodif = 0;
	d->i++;
	return ;
}

int	ft_printf(const char *s, ...)
{
	t_list	d;
	t_flags	f;
	va_list	ap;

	ft_reset_list(&d);
	ft_reset_flags(&f);
	va_start(ap, s);
	while (s[d.i] != '\0')
	{
		while (s[d.i] != '%' && s[d.i])
		{
			write(1, &s[d.i], 1);
			d.ret++;
			d.i++;
		}
		if (s[d.i] != '\0')
			ft_flags(s, &d, &f, &ap);
	}
	va_end(ap);
	return (d.ret);
}
