/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:57:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 14:30:40 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_flag_spaces(char *str, int *index)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	if (str[*index] > '0' && str[*index] <= '9')
	{
		while (i++ < ft_atoi(&str[*index]))
			space++;
		*index += ft_nbrlen(ft_atoi(&str[*index]));
	}
	return (space);
}

int		ft_flag_zero(char *str, int *index, t_flags *flags)
{
	int		i;
	int		zero;

	i = 0;
	zero = 0;
	if (str[*index] == '0')
	{
		*index += 1;
		if (str[*index] == '+')
		{
			flags->plus = ft_flag_plus(index);
			zero--;
		}
		while (i++ < ft_atoi(&str[*index]))
			zero++;
		*index += ft_nbrlen(ft_atoi(&str[*index]));
	}
	return (zero);
}

int		ft_flag_preci(char *str, int *index)
{
	int		value;

	value = 0;
	if (str[*index] == '.')
	{
		*index += 1;
		if (ft_isnumber(str[*index]))
		{
			value = ft_atoi(&str[*index]);
			*index += str[*index] == '0' ? 1 : ft_nbrlen(ft_atoi(&str[*index]));
			if (value == 0)
				return (-1);
		}
		else
			return (-1);
	}
	return (value);
}

int		ft_flag_length(char *str, int *index)
{
	if (str[*index] == 'l' && str[*index + 1] != 'l')
	{
		*index += 1;
		return (1);
	}
	if (str[*index] == 'l' && str[*index + 1] == 'l')
	{
		*index += 2;
		return (2);
	}
	if (str[*index] == 'h' && str[*index + 1] != 'h')
	{
		*index += 1;
		return (3);
	}
	if (str[*index] == 'h' && str[*index + 1] == 'h')
	{
		*index += 2;
		return (4);
	}
	if (str[*index] == 'j')
	{
		*index += 1;
		return (5);
	}
	if (str[*index] == 'z')
	{
		*index += 1;
		return (6);
	}
	return (0);
}
