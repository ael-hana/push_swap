/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 04:05:57 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 04:29:35 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_swap *ptr)
{
	int		i;

	i = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
		++i;
	}
	return (i);
}

void		ft_rev_rotate(t_swap **ptr)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = *ptr;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *ptr;
	*ptr = tmp2;
}

void		rra(t_swap **ptr)
{
	if (!ptr || !*ptr)
		return ;
	if (!(*ptr)->next)
		return ;
	ft_rev_rotate(ptr);
}

void		rrb(t_swap **ptr)
{
	if (!ptr || !*ptr)
		return ;
	if (!(*ptr)->next)
		return ;
	ft_rev_rotate(ptr);
}

void		rrr(t_swap **ptr, t_swap **ptr2)
{
	ft_rev_rotate(ptr);
	ft_rev_rotate(ptr2);
}
