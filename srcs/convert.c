/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:49:41 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/27 18:08:19 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_flag_or_opt(char c)
{
	if (!c)
		return (0);
	if (ft_strchr(CONV, c))
		return (1);
	return (0);
}

void	ch_to_string(int c, t_list *d)
{
	d->bis = malloc(2);
	if (d->bis == NULL)
		return ;
	d->bis[0] = c;
	d->bis[1] = '\0';
	d->bislen = 1;
	if (d->bis[0] == '\0')
		d->bslash = 1;
	return ;
}

void	ft_convert(int c, va_list *ap, t_list *data)
{
	if (c == 'c')
		ch_to_string(va_arg(*ap, int), data);
	if (c == 's')
	{
		data->bis = ft_strdup(va_arg(*ap, char *));
		data->bislen = ft_strlen(data->bis);
	}
	if (c == 'p')
		ft_baseconv((size_t)va_arg(*ap, size_t), "0123456789abcdef", data, c);
	if (c == 'd' || c == 'i')
		ft_baseconv(va_arg(*ap, int), DECI, data, c);
	if (c == 'u')
		ft_baseconv(va_arg(*ap, unsigned int), DECI, data, c);
	if (c == 'x')
		ft_baseconv(va_arg(*ap, unsigned int), "0123456789abcdef", data, c);
	if (c == 'X')
		ft_baseconv(va_arg(*ap, unsigned int), "0123456789ABCDEF", data, c);
	if (c == '%')
		(ch_to_string('%', data));
	return ;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
