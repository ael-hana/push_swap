/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:04 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/21 23:08:12 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_swap(t_swap **ptr, t_swap **ptr2)
{
	t_swap	*old;
	t_swap	*old2;

	old = *ptr;
	old = old->next;
	old = old->next;
	old2 = *ptr2;
	while ((++(*ptr2)->max) && ((*ptr2)->max - 1) != (*ptr2)->i)
		*ptr2 = (*ptr2)->next;
	(*ptr)->next = old;
}

void		pa(t_swap **ptr, t_swap **ptr2)
{
	ft_putstr("pa");
	while ((*ptr2)->i != 1)
		*ptr2 = (*ptr2)->next;
	while (((*ptr)->i) < --(*ptr)->max)
		*ptr = (*ptr)->next;
	ft_swap(ptr, ptr2);
	while ((*ptr)->i != 1)
		*ptr = (*ptr)->next;
	while ((*ptr2)->i != 1)
		*ptr2 = (*ptr2)->next;
}
