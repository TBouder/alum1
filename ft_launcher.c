/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:19:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/29 11:10:25 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum_one.h"

/*
** This function will clear a chained list.
*/

void			ft_list_clear(t_list **begin_list)
{
	t_list	*free_list;
	t_list	*temp;

	if (begin_list != NULL)
	{
		free_list = *begin_list;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			free(temp->content);
			free(temp);
		}
		*begin_list = NULL;
	}
}

/*
** This function will convert a chained list into a simple string
** Used with ft_extract_grid_stdin
*/

static char		*ft_chain_to_string(t_list *list, int len, char *str)
{
	int		i;

	i = 0;
	str = ft_memalloc(len + 1);
	while (i < len)
	{
		str[i] = ((char *)list->content)[0];
		list = list->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
** This function will extract the grid from the standard input (stdin) and
** will stop read it after \n x 2.
*/

static char		*ft_extract_grid_stdin(char *str)
{
	t_list	*list;
	char	buf;

	list = NULL;
	while (read(0, &buf, 1))
	{
		ft_lstend(&list, &buf, 1);
		if (buf == '\n')
		{
			read(0, &buf, 1);
			if (buf == '\n')
			{
				str = ft_chain_to_string(list, ft_lstlen(list), str);
				ft_list_clear(&list);
				return (str);
			}
			ft_lstend(&list, &buf, 1);
		}
	}
	return (NULL);
}

/*
** This function will extract the grid from a file and return it as a string
*/

static char		*ft_extract_grid_file(char *file, int fd, char *str)
{
	int		i;
	char	buf;

	i = 0;
	while (read(fd, &buf, 1) > 0)
		i++;
	if (i == 0)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))) || fd == -1)
		return (NULL);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		str[i++] = buf;
	str[i] = '\0';
	return (str);
}

/*
** Main
*/

int				main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		*nbr;

	fd = open(av[1], O_RDONLY);
	str = NULL;
	nbr = NULL;
	if (ac == 2 && fd != -1)
		str = ft_extract_grid_file(av[1], fd, str);
	else if (ac == 1)
		str = ft_extract_grid_stdin(str);
	if (!(str) || !ft_verifs(str))
	{
		ft_putstr_fd("\033[31mERROR\n\033[0m", 2);
		(str) ? free(str) : 0;
		return (0);
	}
	nbr = ft_convert_as_int(str, nbr);
	free(str);
	ft_game(nbr);
	free(nbr);
	return (0);
}
