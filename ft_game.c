/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 03:02:23 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/21 22:48:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** the ft_whos_first() function tolds us who will play first
*/

static int		ft_whos_first(void)
{
	char	buf;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (read(0, &buf, 1))
	{
		i++;
		if (buf == '1')
			nb = 1;
		else if (buf == '2')
			nb = 2;
		else if (buf == '\n')
		{
			i >= 3 ? nb = 0 : 0;
			if (nb == 0)
				ft_putendl("\033[31mIncorrect input (not 1 or 2)\033[0m");
			return (nb);
		}
	}
	return (0);
}

/*
** The ft_number_to_rm_helper() function helps the ft_number_to_rm() function
*/

static void		ft_number_to_rm_helper(int nb, int len)
{
	if (nb == 0)
		ft_putendl("\033[31mIncorrect input (not 1, 2 or 3)\033[0m");
	else if (nb == -1)
	{
		ft_putstr("\033[31mTo few matches left : \033[0m");
		ft_nbrendl(len);
	}
}

/*
** The ft_number_to_rm_helper() function extracts the number of matches the
** player want to remove
*/

static int		ft_number_to_rm(int len)
{
	char	buf;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (read(0, &buf, 1))
	{
		i++;
		if (buf == '1')
			nb = (len >= 1) ? 1 : -1;
		else if (buf == '2')
			nb = (len >= 2) ? 2 : -1;
		else if (buf == '3')
			nb = (len >= 3) ? 3 : -1;
		else if (buf == '\n')
		{
			i >= 3 ? nb = 0 : 0;
			ft_number_to_rm_helper(nb, len);
			return (nb);
		}
	}
	return (0);
}

/*
** The ft_resolv() function is the main resolution algo
*/

static int		ft_resolv(int *nbr, int len, int first)
{
	int		rm_match;

	while (nbr[0] != 0)
	{
		ft_print_grid(nbr);
		if (first == 1 && first--)
		{
			rm_match = 0;
			ft_putstr("\033[35m\n## -> Number of matches to remove :\033[0m ");
			while (rm_match != 1 && rm_match != 2 && rm_match != 3)
				rm_match = ft_number_to_rm(nbr[len]);
			rm_match = 1;
		}
		else
		{
			ft_putnbr((rm_match = ft_res_ia(nbr, len, nbr[len])));
			first = 1;
		}
		nbr[len] -= rm_match;
		nbr[len] == 0 ? len-- : 0;
	}
	return (first);
}

/*
** The ft_game() function is the game launcher function
*/

int				ft_game(int *nbr)
{
	int		first;
	int		result;

	first = 0;
	ft_putendl("\n		   \033[44;1m--- Welcome to Alum1 ---\033[0m");
	ft_putendl("	--- Each turn, you'll be invited to enter a ---");
	ft_putendl("	---   number of matches you want to remove  ---");
	ft_putendl("	---   You win if the IA takes the last one  ---");
	ft_putstr("\n## -> Will you start ? (1 : player | 2 : IA) : ");
	while (first != 1 && first != 2)
		first = ft_whos_first();
	result = ft_resolv(nbr, ft_count_grid_nbr(nbr) - 1, first);
	if (result == 1)
		ft_putendl("\033[32;1m\n			--- YOU WIN ---\033[0m");
	else
		ft_putendl("\033[31;1m\n			--- YOU LOSE ---\033[0m");
	return (0);
}
