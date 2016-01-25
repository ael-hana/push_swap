/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:48:31 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/25 06:24:01 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_size_list(t_swap *ptr)
{
	int	i;

	i = 1;
	while ((ptr = ptr->next))
		++i;
	return (i);
}

void			ft_check_int(char *av)
{
	int			i;
	char		*str;
	char		*strn;

	str = "2147483647";
	strn = "2147483648";
	i = 0;
	while (av[i] && (av[i] == str[i] || av[i] == strn[i]))
		++i;
	if (av[i])
		ft_error();
}

void			ft_check_overflow(char *av)
{
	unsigned int	i;

	i = 0;
	if (*av == '-')
		av++;
	if (ft_strlen(av) > ft_strlen("2147483647"))
		ft_error();
	if (ft_strlen(av) == ft_strlen("2147483647"))
		ft_check_int(av);
	while (ft_isdigit(av[i]))
		++i;
	if (av[i])
		ft_error();
}

unsigned char	ft_check_params(int ac, char **av)
{
	int				i;
	int				index;

	if (ac < 2)
		ft_error();
	i = 1;
	if (!ft_strcmp(av[i], "-v"))
		i++;
	while (ac > i)
		ft_check_overflow(av[i++]);
	index = 1;
	while (ac > index)
	{
		i = 2;
		while (i < ac && i != index)
		{
			if (!ft_strcmp(av[i], av[index]))
				ft_error();
			++i;
		}
		++index;
	}
	return (ft_strcmp(av[1], "-v") == 0 ? -42 : 0);
}
