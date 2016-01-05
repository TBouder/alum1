/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_as_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:49:03 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/21 22:51:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** The ft_count_grid_nbr() function is used to malloc our INT grid.
** It will count the number of numbers.
*/

int				ft_count_grid_nbr(int *nbr)
{
	int		i;

	i = 0;
	while (nbr[i])
		i++;
	return (i);
}

/*
** The ft_count_grid() function is used to malloc our CHAR grid.
** It will count the number of numbers.
*/

int				ft_count_grid(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		i += ft_linelen(str, i) + 1;
		k++;
	}
	return (k);
}

/*
** The ft_convert_as_int() converts our CHAR* in INT*
*/

int				*ft_convert_as_int(char *str, int *nbr)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = ft_count_grid(str);
	if (!(nbr = (int *)malloc(sizeof(int) * (nb + 1))))
		return (0);
	while (i < nb)
	{
		nbr[i] = ft_atoi_part(str, j);
		j += ft_linelen(str, j) + 1;
		i++;
	}
	nbr[i] = 0;
	return (nbr);
}
