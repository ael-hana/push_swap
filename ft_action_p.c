/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:04 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 04:57:06 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_add(t_swap **ptr2, int data)
{
	t_swap	*ptr;

	ptr = *ptr2;
	if (!ptr)
	{
		*ptr2 = ft_init_list(ft_itoa(data));
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ft_init_list(ft_itoa(data));
}

void		ft_swap(t_swap **ptr1, t_swap **ptr2)
{
	void	*tmp;

	tmp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = (*ptr1)->next;
	(*ptr2)->next = tmp;
}

void		pa(t_swap **ptr, t_swap **ptr2)
{
	if (*ptr)
		ft_swap(ptr, ptr2);
}

void		pb(t_swap **ptr, t_swap **ptr2)
{
	if (*ptr)
		ft_swap(ptr, ptr2);
}
