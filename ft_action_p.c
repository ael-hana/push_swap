/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:04 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 03:37:19 by ael-hana         ###   ########.fr       */
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
	int		i;
	void	*tmp;
	t_swap	*ptr;

	ptr = *ptr1;
	tmp = ptr;
	i = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
		++i;
	}
	ft_add(ptr2, ptr->data);
	free(ptr);
	ptr = tmp;
	while (--i > 0)
		ptr = ptr->next;
	ptr->next = NULL;
}

void		pa(t_swap **ptr, t_swap **ptr2)
{
	ft_putstr("sa");
	ft_swap(ptr, ptr2);
}

void		pb(t_swap **ptr, t_swap **ptr2)
{
	ft_putstr("sb");
	ft_swap(ptr, ptr2);
}
