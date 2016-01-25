#include "ft_list.h"

void		ft_algo(t_tab **op, t_swap **ba, t_swap **bb, unsigned int i)
{
	if (i / 8)
		ft_algo(op, ba, bb, (i / 8));
	if (i % 8 < 3)
		op[i % 8](ba);
	else if (i % 8 == 3 && *bb)
		pb(bb, ba);
	else if (i % 8 == 4 && *ba)
		pa(ba, bb);
	else if (i % 8 == 5)
		op[3](bb);
	else if (i % 8 == 6)
		op[4](bb);
	else if (i % 8 == 7)
		op[5](bb);
}

void		ft_algo_remove(t_swap **ba, t_swap **bb)
{
	t_swap	*tmp;

	while (*ba && (tmp = (*ba)->next))
	{
		free(*ba);
		*ba = tmp;
	}
	if (tmp)
		free(tmp);
	while (*bb && (tmp = (*bb)->next))
	{
		free(*bb);
		*bb = tmp;
	}
	if (tmp)
		free(tmp);
	*bb = NULL;
}

void		ft_put_sol(unsigned int i)
{
	if (i / 8)
		ft_put_sol(i / 8);
	if (i % 8 == 0)
		ft_putstr("sa ");
	else if (i % 8 == 1)
		ft_putstr("ra ");
	else if (i % 8 == 2)
		ft_putstr("rra ");
	else if (i % 8 == 3)
		ft_putstr("pa ");
	else if (i % 8 == 4)
		ft_putstr("pb ");
	else if (i % 8 == 5)
		ft_putstr("sb ");
	else if (i % 8 == 6)
		ft_putstr("rb ");
	else if(i % 8 == 7)
		ft_putstr("rrb ");
}
