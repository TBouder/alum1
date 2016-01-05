/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 23:51:14 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 13:25:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** Find the greater number in nbr
*/

static int		ft_greater(int *nbr)
{
	int		i;
	int		gr;

	i = 0;
	gr = 0;
	while (nbr[i])
	{
		if (nbr[i] > gr)
			gr = nbr[i];
		i++;
	}
	return (gr);
}

/*
** This function will transform the input number as |
*/

static void		ft_print_pipe(int nb, int gr)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (i < nb)
		i++;
	len = i;
	i = 0;
	ft_putstr("\033[33;1m[");
	ft_putnbr(len);
	ft_putstr("]\033[0m");
	ft_putstr("\t\t\t");
	while (gr - len - ((gr - len) / 2) > j++)
		ft_putchar(' ');
	while (i < nb)
	{
		ft_putchar('|');
		i++;
	}
	ft_putchar('\n');
}

/*
** This function allows us to print the grid
*/

void			ft_print_grid(int *nbr)
{
	int		i;
	int		gr;

	i = 0;
	gr = ft_greater(nbr);
	ft_putchar('\n');
	while (nbr[i])
		ft_print_pipe(nbr[i++], gr);
}
