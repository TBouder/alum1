/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_one.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:08:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/09 21:54:07 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_ONE_H
# define ALUM_ONE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

int				ft_verifs(char *str);
void			ft_print_grid(int *nbr);
int				*ft_convert_as_int(char *str, int *nbr);
int				ft_game(int *nbr);
int				ft_count_grid_nbr(int *nbr);
int				ft_res_ia(int *nbr, int index, int len);

#endif
