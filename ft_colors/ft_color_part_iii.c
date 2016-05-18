/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_part_iii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:09:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 22:20:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define W write
#define	O str[*index + 1]
#define	T str[*index + 2]
#define	R str[*index + 3]
#define	F str[*index + 4]

/*
** Some modifier for color shape
** 9698 : ◢
** 9699 : ◣
** 9700 : ◤
** 9701 : ◥
** 9607 : ▇
** 11044 : ⬤
*/

static void	ft_print_all_colors(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 15)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[38;5;", i, "m", 9607, i, "\e[0m");
		if (!((i + 1) % 6))
			ft_putchar('\n');
		i++;
	}
	ft_putendl("\n");
	while (i <= 256)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[38;5;", i, "m", 9607, i, "\e[0m");
		if (i == 51 || i == 87 || i == 123 || i == 159 || i == 195 || i == 231)
			ft_putstr("\n\n");
		else if (!((j + 1) % 6))
			ft_putstr("\n");
		i++;
		j++;
	}
	ft_putchar('\n');
}

void	ft_color_part_11(const char *str, int *index)
{
	O == '2' && T == '2' && R == '5' && F == '}' ? W(1, "\e[38;5;225m", 11) : 0;
	O == '2' && T == '2' && R == '6' && F == '}' ? W(1, "\e[38;5;226m", 11) : 0;
	O == '2' && T == '2' && R == '7' && F == '}' ? W(1, "\e[38;5;227m", 11) : 0;
	O == '2' && T == '2' && R == '8' && F == '}' ? W(1, "\e[38;5;228m", 11) : 0;
	O == '2' && T == '2' && R == '9' && F == '}' ? W(1, "\e[38;5;229m", 11) : 0;
	O == '2' && T == '3' && R == '0' && F == '}' ? W(1, "\e[38;5;230m", 11) : 0;
	O == '2' && T == '3' && R == '1' && F == '}' ? W(1, "\e[38;5;231m", 11) : 0;
	O == '2' && T == '3' && R == '2' && F == '}' ? W(1, "\e[38;5;232m", 11) : 0;
	O == '2' && T == '3' && R == '3' && F == '}' ? W(1, "\e[38;5;233m", 11) : 0;
	O == '2' && T == '3' && R == '4' && F == '}' ? W(1, "\e[38;5;234m", 11) : 0;
	O == '2' && T == '3' && R == '5' && F == '}' ? W(1, "\e[38;5;235m", 11) : 0;
	O == '2' && T == '3' && R == '6' && F == '}' ? W(1, "\e[38;5;236m", 11) : 0;
	O == '2' && T == '3' && R == '7' && F == '}' ? W(1, "\e[38;5;237m", 11) : 0;
	O == '2' && T == '3' && R == '8' && F == '}' ? W(1, "\e[38;5;238m", 11) : 0;
	O == '2' && T == '3' && R == '9' && F == '}' ? W(1, "\e[38;5;239m", 11) : 0;
	O == '2' && T == '4' && R == '0' && F == '}' ? W(1, "\e[38;5;240m", 11) : 0;
	O == '2' && T == '4' && R == '1' && F == '}' ? W(1, "\e[38;5;241m", 11) : 0;
	O == '2' && T == '4' && R == '2' && F == '}' ? W(1, "\e[38;5;242m", 11) : 0;
	O == '2' && T == '4' && R == '3' && F == '}' ? W(1, "\e[38;5;243m", 11) : 0;
	O == '2' && T == '4' && R == '4' && F == '}' ? W(1, "\e[38;5;244m", 11) : 0;
	O == '2' && T == '4' && R == '5' && F == '}' ? W(1, "\e[38;5;245m", 11) : 0;
	O == '2' && T == '4' && R == '6' && F == '}' ? W(1, "\e[38;5;246m", 11) : 0;
	O == '2' && T == '4' && R == '7' && F == '}' ? W(1, "\e[38;5;247m", 11) : 0;
	O == '2' && T == '4' && R == '8' && F == '}' ? W(1, "\e[38;5;248m", 11) : 0;
	O == '2' && T == '4' && R == '9' && F == '}' ? W(1, "\e[38;5;249m", 11) : 0;
}

void	ft_color_part_12(const char *str, int *index)
{
	O == '2' && T == '5' && R == '0' && F == '}' ? W(1, "\e[38;5;250m", 11) : 0;
	O == '2' && T == '5' && R == '1' && F == '}' ? W(1, "\e[38;5;251m", 11) : 0;
	O == '2' && T == '5' && R == '2' && F == '}' ? W(1, "\e[38;5;252m", 11) : 0;
	O == '2' && T == '5' && R == '3' && F == '}' ? W(1, "\e[38;5;253m", 11) : 0;
	O == '2' && T == '5' && R == '4' && F == '}' ? W(1, "\e[38;5;254m", 11) : 0;
	O == '2' && T == '5' && R == '5' && F == '}' ? W(1, "\e[38;5;255m", 11) : 0;
	O == 'A' && T == '}' ? ft_print_all_colors() : 0;
}
