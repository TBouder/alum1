/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_ia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:15:48 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/21 22:49:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** The ft_res_ia() function is the algo giving us the number of matches the
** AI have to remove to win (If possible)
*/

int		ft_res_ia(int *nbr, int index, int len)
{
	int			nb;
	int			r;

	ft_putstr("\033[36m\n## -> Computeur has remove : \033[0m");
	if (len == 4 || len == 3 || len == 2)
		if (nbr[index - 1] <= 3 && nbr[index - 1] != 1)
			return (len - 1);
	if ((len == 3 || len == 2) && index != 0 && nbr[index - 1] % 4 == 1)
		return (len);
	if (len == 1)
		return (1);
	nb = (len % 4 == 0) ? 3 : 0;
	nb = (len % 4 == 3) ? 2 : 0;
	nb = (len % 4 == 2) ? 1 : 0;
	if (len % 4 == 1 || nb == 0)
	{
		while ((r = ft_rand(4)) == 0)
			;
		return (r);
	}
	return (nb);
}
