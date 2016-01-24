/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 03:40:16 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 04:00:38 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_rotate(t_swap **ptr)
{
	t_swap	*tmp;
	void	*ret;

	tmp = *ptr;
	*ptr = (*ptr)->next;
	ret = *ptr;
	while ((*ptr)->next)
		*ptr = (*ptr)->next;
	(*ptr)->next = tmp;
	*ptr = (*ptr)->next;
	(*ptr)->next = NULL;
	*ptr = ret;
}

void	ra(t_swap **ptr)
{
	if (!*ptr)
		return ;
	ft_rotate(ptr);
}

void	rb(t_swap **ptr)
{
	if (!*ptr)
		return ;
	ft_rotate(ptr);
}

void	rr(t_swap **ptr, t_swap **ptr2)
{
	ft_rotate(ptr);
	ft_rotate(ptr2);
}
