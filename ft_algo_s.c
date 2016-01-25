/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:09:51 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/25 03:25:36 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_algo_sort_s(t_tab **op, t_swap **ba, unsigned int i)
{
	int		min;

	min = (*ba)->data;
	while (!ft_sorted(*ba))
	{
		if ((*ba)->data > (*ba)->next->data)
		{
			sa(ba);
			ft_putstr("sa ");
			if (min > (*ba)->data)
				min = (*ba)->data;
			while (min != (*ba)->data)
			{
				rra(ba);
				ft_putstr("rra ");
			}
		}
		else
		{
			ra(ba);
			ft_putstr("rra ");
		}
	}
}

void		ft_put_sol_s(unsigned int i)
{
	if (i / 3)
		ft_put_sol(i / 3);
	if (i % 3 == 0)
		ft_putstr("sa ");
	else if (i % 3 == 1)
		ft_putstr("ra ");
	else if (i % 3 == 2)
		ft_putstr("rra ");
}
