/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:52:28 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 20:29:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_r_justified(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - s_local_pa > 0)
	{
		while (flags->spaces-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
	else if (flags->spaces == 0 && flags->zero != 0)
	{
		while (flags->zero-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
}

void	ft_flag_l_justified(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	if (flags->spaces + s_local_pa < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

void	ft_put_precision(t_flags flags, long long local_pa, int base, int maj)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(ft_itoa_base(local_pa, base));
	while (flags.precision - len > 0)
	{
		ft_putchar('0');
		flags.precision -= 1;
	}
	ft_putnbr_base(local_pa, base, maj);
}

void	ft_put_precision_str(t_flags flags, char *local_pa)
{
	int		i;

	i = 0;
	while (i != flags.precision && local_pa[i])
	{
		ft_putchar(local_pa[i]);
		i++;;
	}
}
