/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:48:31 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/20 18:23:47 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
	while (ft_isdigit(av[i++]));
	if (av[--i])
		ft_error();
}

unsigned char	ft_check_params(int ac, char **av)
{
	unsigned int	i;

	if (ac < 2)
		ft_error();
	i = 1;
	while (ac > i)
		ft_check_overflow(av[i++]);
	return (0);
}
