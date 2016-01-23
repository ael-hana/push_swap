/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:24:39 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 14:53:38 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_swap		*ft_sa(t_swap *ptr)
{
	t_swap	*tmp;
	t_swap	*start;

	start = ptr;
	tmp = ptr->next;
	tmp = tmp->next;
	ptr = ptr->next;
	start->next = tmp;
	ptr->next = start;
	return (ptr);
}

void		sa(t_swap **ptr)
{
	t_swap	*tmp;

	tmp = (*ptr)->next;
	if (!tmp || tmp->data > (*ptr)->data)
		return ;
	*ptr = ft_sa(*ptr);
}

void		sb(t_swap **ptr)
{
	t_swap	*tmp;

	tmp = (*ptr)->next;
	if (!tmp || tmp->data > (*ptr)->data)
		return ;
	*ptr = ft_sa(*ptr);
}

void		ft_ss(t_swap **ptr, t_swap **ptr2)
{
	ft_putstr("ss");
	*ptr = ft_sa(*ptr);
	*ptr2 = ft_sa(*ptr2);
}
