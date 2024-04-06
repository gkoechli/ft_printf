/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:01:34 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/13 14:52:37 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_subsprec(t_list *d, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return ;
	while (len-- > 0)
	{
		sub[i] = d->bis[i];
		i++;
	}
	sub[i] = '\0';
	free(d->bis);
	d->bis = ft_strdup(sub);
	free(sub);
	d->bislen = i;
	return ;
}

char	*ft_substrf(const char *s, t_list *d, size_t len)
{
	size_t	u;
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < d->i)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	u = -1;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (len > ++u)
		sub[u] = s[u + d->i];
	sub[u] = '\0';
	d->bis = ft_strdup(sub);
	free(sub);
	d->bislen = len;
	return (d->bis);
}

void	add_char_before(t_list *d, char c)
{
	char	*str;
	int		len;

	d->match = 0;
	len = 1;
	d->bislen = 1;
	if (d->bis == 0)
		d->match = 1;
	else
		len = ft_strlen(d->bis) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return ;
	str[0] = c;
	while (d->match == 0 && d->bis[d->bislen - 1])
	{
		str[d->bislen] = d->bis[d->bislen - 1];
		d->bislen++;
	}
	str[d->bislen] = '\0';
	free(d->bis);
	d->bis = ft_strdup(str);
	free(str);
	return ;
}

void	add_char_after(t_list *d, char c)
{
	char	*str;
	int		len;

	d->match = 0;
	len = 1;
	if (d->bis == 0)
		d->match = 1;
	else
		len = d->bislen + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return ;
	d->bislen = 0;
	while (d->match == 0 && d->bis[d->bislen])
	{
		str[d->bislen] = d->bis[d->bislen];
		d->bislen++;
	}
	str[d->bislen++] = c;
	str[d->bislen] = '\0';
	free(d->bis);
	d->bis = ft_strdup(str);
	free(str);
	return ;
}
