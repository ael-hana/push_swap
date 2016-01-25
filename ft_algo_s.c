/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:09:51 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/25 06:38:18 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_swap		*ft_init_list(char *av)
{
	t_swap	*ptr;

	if (!(ptr = malloc(sizeof(t_swap))))
		ft_error();
	ptr->next = NULL;
	ptr->data = ft_atoi(av);
	return (ptr);
}

t_swap		*ft_creat_list(int max, char **av)
{
	int		i;
	void	*save;
	t_swap	*ptr;

	i = 1;
	if (!ft_strcmp(av[1], "-v"))
		++i;
	ptr = ft_init_list(av[i++]);
	save = ptr;
	while (i <= max)
	{
		ptr->next = ft_init_list(av[i++]);
		ptr = ptr->next;
	}
	return (save);
}

void		ft_print_param(t_swap **ba, unsigned int i, char op)
{
	if (op)
	{
		ra(ba);
		ft_putstr("ra ");
	}
	i ? ft_print_list(*ba, 1) : 0;
	i ? ft_print_list(NULL, 0) : 0;
}

void		ft_algo_sort_s(t_swap **ba, unsigned int i)
{
	int		min;

	min = (*ba)->data;
	while (!ft_sorted(*ba))
	{
		if ((*ba)->data > (*ba)->next->data)
		{
			sa(ba);
			ft_putstr("sa ");
			ft_print_param(ba, i, 0);
			if (min > (*ba)->data)
				min = (*ba)->data;
			while (min != (*ba)->data)
			{
				rra(ba);
				ft_putstr("rra ");
				ft_print_param(ba, i, 0);
			}
		}
		else
			ft_print_param(ba, i, 1);
	}
	ft_putchar('\n');
}

void		ft_put_sol_s(unsigned int i)
{
	if (i / 3)
		ft_put_sol_s(i / 3);
	if (i % 3 == 0)
		ft_putstr("sa ");
	else if (i % 3 == 1)
		ft_putstr("ra ");
	else if (i % 3 == 2)
		ft_putstr("rra ");
}
