/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:24:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 13:52:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_put_preci_hex_ll(t_flags *flags, long long local_pa, int maj)
{
	int		len;

	len = ft_strlen(ft_itoa_base(local_pa, 16));
	while (flags->precision - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count += 1;
		flags->precision -= 1;
	}
	ft_putnbr_base_ull(local_pa, 16, maj);
}

void		ft_put_preci_hex(t_flags *flags, long long local_pa, int maj)
{
	int		len;

	len = ft_strlen(ft_itoa_base(local_pa, 16));
	while (flags->precision - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count += 1;
		flags->precision -= 1;
	}
	if (ft_itoa_base(local_pa, 16)[0] == '0' && flags->precision != -1)
		ft_putnbr_base(local_pa, 16, maj);
	else if (ft_itoa_base(local_pa, 16)[0] != '0')
		ft_putnbr_base(local_pa, 16, maj);
}

void		ft_before_hex(t_flags *flags, int s_local_pa, long long value, int maj)
{
	if (flags->spaces && flags->spaces - s_local_pa > 0)
	{
		while (flags->spaces-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
		(flags->precision == -1) ? ft_putchar(' ') : 0;
		(flags->precision == -1) ? flags->spaces_count++ : 0;
	}
	else if (flags->spaces >= -2 && flags->zero != 0)
	{
		(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
		(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
		maj = -1;
		while (flags->zero-- + flags->spaces - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
	(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
	(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
	(flags->diaiz == 1) && (value != 0) ? flags->spaces_count += 2 : 0;
}

void		ft_after_hex(t_flags *flags, int s_local_pa)
{
	if (flags->diaiz)
		flags->spaces += 2;
	if (flags->spaces + s_local_pa < 0)
	{
		while (flags->spaces++ + s_local_pa < 0 - flags->diaiz * 2)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int			ft_launch_conv_x_X(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'X')
	{
		if (flags.length == 1 || flags.length == 2 || flags.length == 5)
			return (ft_conv_X_l(*pa, flags, str + index));
		else
			return (ft_conv_X(*pa, flags, str + index));
	}
	else if (str[index] == 'x')
	{
		if (flags.length == 1 || flags.length == 2 || flags.length == 5)
			return (ft_conv_x_l(*pa, flags, str + index));
		else
			return (ft_conv_x(*pa, flags, str + index));
	}
	return (0);
}