/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:04 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/21 19:21:54 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_swap(t_swap **ptr, t_swap **ptr2)
{
	t_swap	*old;

	while (((*ptr)->i + 1) < (*ptr)->max)
		*ptr = (*ptr)->next;
	old = *ptr;
	(*ptr)->next = old;
	while ((*ptr2)->i != 1)
		*ptr2 = (*ptr2)->next;
	while ((++(*ptr2)->max) && ((*ptr2)->max - 1) != (*ptr2)->i)
		*ptr2 = (*ptr2)->next;
	
}

void		pa(t_swap **ptr, t_swap **ptr2)
{
	ft_putstr("pa");
}
