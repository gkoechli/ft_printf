/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:53:56 by gkoechli          #+#    #+#             */
/*   Updated: 2021/10/13 14:51:44 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define CONV "cspdiuxX%"
# define PRECI "diuxX"
# define NUFLGS "123456789"
# define DECI "0123456789"

typedef struct s_flags
{
	int	preci;
	int	min;
	int	zero;
	int	num;
	int	field;
	int	pmodif;
}				t_flags;

typedef struct s_list
{
	int		i;
	int		j;
	int		ret;
	int		match;
	int		sign;
	int		bislen;
	int		c;
	int		bslash;
	char	*bis;
}				t_list;

int			ft_strncmp(const char *s1, const char *s2, size_t size);
int			ft_intlen(size_t n, long s);
int			ft_printf(const char *s, ...);
char		*ft_strchr(const char *str, int c);
int			is_flag_or_opt(char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_precichar(t_list *d, t_flags *f);
void		ch_to_string(int c, t_list *d);
void		ft_flags(const char *s, t_list *d, t_flags *f, va_list *ap);
void		ft_baseconv(size_t n, char *s, t_list *d, char c);
void		ft_convert(int c, va_list *ap, t_list *d);
void		ft_zmp(const char *s, t_list *d, t_flags *f);
int			ft_num(const char *s, t_list *d, t_flags *f);
int			ft_strlen(const char *s);
void		ft_zero(t_list *d, t_flags *f);
void		ft_minus(t_list *d, t_flags *f);
void		ft_precision(t_list *d, t_flags *f);
void		ft_field(t_list *d, t_flags *f);
void		ft_convert_opt(t_list *d, t_flags *f, va_list *ap);
void		add_char_after(t_list *d, char c);
void		add_char_before(t_list *d, char c);
void		ft_fill(long n, t_list *d, int intlen, char *s);
void		ft_fillp(unsigned long n, t_list *d, int intlen, char *s);
void		ft_subsprec(t_list *d, size_t len);
char		*ft_substrf(const char *s, t_list *d, size_t len);
char		*ft_strdup(const char *s);
void		ft_reset_list(t_list *s);
void		ft_reset_flags(t_flags *f);
#endif
