/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:26:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 13:59:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	ft_put_preci_ll(t_flags flags, long long local_pa)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen_ll(local_pa);
	while (flags.precision - len > 0)
	{
		ft_putchar('0');
		flags.precision -= 1;
	}
	if (local_pa < 0)
		ft_putchar('-');
	ft_putnbr_ll(local_pa);
}


int		ft_conv_d_i(va_list pa, t_flags flags, char *str)
{
	int		local_pa;
	int		sign;
	int		space;
	int		len;

	local_pa = va_arg(pa, int);
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	sign = local_pa < 0 ? 1 : 0;
	len = ft_nbrlen(local_pa) == 0 ? 1 : ft_nbrlen(local_pa);
	ft_flag_r_justified(&flags, len);
	ft_put_precision(flags, local_pa, 10, 0);
	ft_flag_l_justified(&flags, len + sign);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_l(va_list pa, t_flags flags, char *str)
{
	long	local_pa;
	int		sign;
	int		space;
	int		len;

	local_pa = va_arg(pa, long);
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	sign = local_pa < 0 ? 1 : 0;
	len = ft_nbrlen_l(local_pa) == 0 ? 1 : ft_nbrlen_l(local_pa);
	ft_flag_r_justified(&flags, len);
	ft_put_precision(flags, local_pa, 10, 0);
	ft_flag_l_justified(&flags, len + sign);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_ll(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, long long);

	sign = local_pa < 0 ? 1 : 0;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	len = ft_nbrlen_ll(local_pa) == 0 ? 1 : ft_nbrlen_ll(local_pa);
	ft_flag_r_justified(&flags, len);
	ft_put_preci_ll(flags, local_pa);
	ft_flag_l_justified(&flags, len + sign);

	return (len + flags.spaces_count + sign + space);
}

int		ft_launch_conv_d_i(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'd' || str[index] == 'i')
	{
		if (flags.length == 1)
			return (ft_conv_d_i_l(*pa, flags, str + index));
		else if (flags.length == 2)
			return (ft_conv_d_i_ll(*pa, flags, str + index));
		else
			return (ft_conv_d_i(*pa, flags, str + index));
	}
	return (0);
}
