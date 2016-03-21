/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 19:14:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_precision_str() function adjusts the precision before displaying
** the output.
*/

void	ft_put_precision_str(t_flags flags, char *local_pa, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		(flags.preci == -1 && (!flags.display)) ? ft_putchar(' ') : 0;
		(flags.preci != -1 && (!flags.display)) ? ft_putchar(local_pa[i]) : 0;
		i++;;
	}
}

/*
** The ft_before_str() add spaces before if needed //RISQUE DE CHANGER.
*/

void	ft_before_str(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces - v_len != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
	else if (flags->zero && flags->zero - v_len > 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

/*
** The ft_after_str() function adds spaces after the output when the conditions
** are met.
*/

void	ft_after_str(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

/*
** The ft_launch_conv_s_S() function launchs the conversion by s or S.
*/

int		ft_launch_conv_s_S(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 's')
	{
		return (ft_conv_s(*pa, flags));
	}
	if (str[index] == 'S')
	{
		return (ft_conv_S(*pa, flags));
	}
	return (0);
}
