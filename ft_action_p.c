/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:04 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/21 18:50:14 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		pa(t_swap **ptr, t_swap **ptr2)
{
	char	*str;
	void	*old;

	ft_putstr("pa");
	while ((*ptr)->i != (*ptr)->max)
		*ptr = (*ptr)->next;
	str = ft_itoa((*ptr)->i);
	if (!*ptr2)
	{
		*ptr2 = ft_creat_list(1, &str);
	}
}
