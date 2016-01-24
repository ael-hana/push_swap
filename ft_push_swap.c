/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:10:42 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 18:51:38 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

	i = 2;
	ptr = ft_init_list(av[1]);
	save = ptr;
	while (i <= max)
	{
		ptr->next = ft_init_list(av[i++]);
		ptr = ptr->next;
	}
	return (save);
}

char		ft_sorted(t_swap *ptr)
{
	t_swap	*av;
	int		i;

	av = ptr->next;
	i = 0;
	while (av && av->data > ptr->data)
	{
		++i;
		av = av->next;
		ptr = ptr->next;
	}
	if (av)
		return (0);
	return (1);
}

void		ft_print_list(t_swap *ptr)
{
	while (ptr->next)
	{
		ft_putstr("\nla data est ");
		ft_putnbr(ptr->data);
		ptr = ptr->next;
	}
	ft_putstr("\nla data est ");
	ft_putnbr(ptr->data);
	ft_putchar('\n');
}

t_tab		**ft_pt_op(void)
{
		t_tab	**op;

	if (!(op = malloc(sizeof(t_tab **) * 6)))
		ft_error();
	op[0] = &sa;
	op[1] = &ra;
	op[2] = &rra;
	op[3] = &sb;
	op[4] = &rb;
	op[5] = &rrb;
	return (op);
}

void		ft_algo(t_tab **op, t_swap **ba, t_swap **bb, unsigned int i)
{
	if (i / 8)
		ft_algo(op, ba, bb, (i / 8));
	if (i % 8 < 3)
		op[i % 8](ba);
	else if (i % 8 == 3 && *bb)
		pb(bb, ba);
	else if (i % 8 == 4)
		pa(ba, bb);
	else if (i % 8 == 5)
		op[3](bb);
	else if (i % 8 > 4)
		op[i % 8 == 6 ? 4 : 5](bb);
}

void		ft_algo_remove(t_tab **op, t_swap **ba, t_swap **bb, unsigned int i)
{
	if (i / 8)
		ft_algo(op, ba, bb, (i / 7));
	if (i % 8 < 3)
	{
		if (i % 8 == 0)
			op[0](ba);
		else
			op[i % 8 == 1 ? 2 : 1](ba);
	}
	else if (i % 8 == 3 && *bb)
		pa(ba, bb);
	else if (i % 8 == 4)
		pb(bb, ba);
	else if (i % 8 > 4)
		if (i % 8 == 5)
			op[3](bb);
		else 
			op[i % 8 == 6 ? 5 : 4](bb);
}

void				ft_put_sol(unsigned int i)
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
		ft_putstr("pb ");
	else if (i % 8 == 4)
		ft_putstr("pa ");
	if (i % 8 == 5)
		ft_putstr("sb ");
	else if (i % 8 == 6)
		ft_putstr("rb ");
	else
		ft_putstr("rrb ");
}

void				call_algo(t_swap **ba, t_swap **bb)
{
	void			*tmp;
	unsigned int	i;

	tmp = ft_pt_op();
	i = 0;

	ft_algo(tmp, ba, bb, i);
		ft_put_sol(i);
	ft_print_list(*ba);
	while (!ft_sorted(*ba) || *bb)
	{
		ft_algo_remove(tmp, ba, bb, i);
		ft_algo(tmp, ba, bb, ++i);
		ft_put_sol(i);
		ft_putstr("*********************************************______________**************");
		if (*ba)
			ft_print_list(*ba);
		if (*bb)
			ft_print_list(*bb);
		ft_putnbr(i);
		ft_putstr("*********************************************\n\n\n\n\n");
	}
	ft_put_sol(i);
}

int			main(int ac, char **av)
{
	t_swap	*ba;
	t_swap	*bb;

	bb = NULL;
	ft_check_params(ac, av);
	ft_print_list((ba = ft_creat_list(ac - 1, av)));
	ft_putstr("*********************************************\n");
	ft_print_list(ba);
	ft_putstr("*********************************************\n");
	if (ft_sorted(ba))
		return (0);
//	ft_put_sol(35);
//	call_algo(&ba, &bb);
	rra(&ba);
	ft_print_list(ba);
	return (0);
}
