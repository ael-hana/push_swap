
#include "ft_list.h"

void		ft_algo_sort_s(t_tab **op, t_swap **ba, unsigned int i)
{
/*	if (i / 3)
		ft_algo_sort_s(op, ba, i / 3);
	if (!(i % 3))
		op[i % 3](ba);
	else if (i % 3 == 1)
		op[i % 3](ba);
	else
		op[i % 3](ba);*/
	int		min;

	min = (*ba)->data;
	while (!ft_sorted(*ba))
	{
		if (min > (*ba)->data)
		{
			min = (*ba)->data;
			while (min != (*ba)->data)
				ra(ba);
		}
		if ((*ba)->data > (*ba)->next->data)
		{
			sa(ba);
			while (min != (*ba)->data)
				ra(ba);
		}
		else
			rra(ba);
	}
}

void		ft_put_sol_s(unsigned int i)
{
	if (i / 3)
		ft_put_sol(i / 3);
	if (i % 3 == 0)
		ft_putstr("sa ");
	else if (i % 3 == 1)
		ft_putstr("ra ");
	else if (i % 3 == 2)
		ft_putstr("rra ");
}
