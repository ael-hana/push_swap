/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:24:39 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/20 22:37:23 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sa(t_swap *ptr)
{
	void	*tmp;
	void	*tmp2;
	void	*tmp3;
	t_swap	*prev;

	if (!(ptr->max - 2))
	{
		ptr->i = 2;
		ptr = ptr->next;
		ptr->i = 1;
		return ;
	}
	while (ptr->i != (ptr->max - 2))
		ptr = ptr->next;
	prev = ptr;
	ptr = ptr->next;
	ptr->i = ptr->max;
	tmp = ptr;
	ptr = ptr->next;
	ptr->i = (ptr->max - 1);
	tmp2 = ptr;
	tmp3 = ptr->next;
	ptr->next = tmp;
	ptr = ptr->next;
	ptr->next = tmp3;
	prev->next = tmp2;
}

void	sa(t_swap *ptr)
{
	ft_putstr("sa");
	ft_sa(ptr);
}

void	ft_sb(t_swap *ptr)
{
	ft_sa(ptr);
}

void	sb(t_swap *ptr)
{
	ft_putstr("sb");
	ft_sa(ptr);
}

void	ft_ss(t_swap *ptr, t_swap *ptr2)
{
	ft_putstr("ss");
	ft_sa(ptr);
	ft_sb(ptr2);
}
