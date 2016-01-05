/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 23:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 15:50:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** This function will test if the input number is nor 0 nor over 10000
*/

static int		ft_verif_grid(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi_part(str, i) == 0 || ft_atoi_part(str, i) > 10000)
			return (0);
		i += ft_linelen(str, i) + 1;
	}
	return (1);
}

/*
** This function will test if there is only numbers or '\n' as input numbers
*/

static int		ft_verif_o_nb(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isnumber(str[i]) == 0 && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** This function will test if there is no empty line
*/

static int		ft_verif_empty_ln(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** This launcher will launch various verification tests
*/

int				ft_verifs(char *str)
{
	if (!ft_verif_o_nb(str) || !ft_verif_empty_ln(str) || !ft_verif_grid(str))
		return (0);
	return (1);
}
