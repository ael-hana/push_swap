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

	if (!(op = malloc(sizeof(t_tab **) * 8)))
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
	void	*tmp;

	tmp = op;
	if (i / 3)
		ft_algo(tmp, ba, bb, (i / 3));
	op[i % 3](ba);
}

void		ft_algo_remove(t_tab **op, t_swap **ba, t_swap **bb, unsigned int i)
{
	if (i / 3)
		ft_algo(op, ba, bb, (i / 3));
	if (i % 3 == 0)
		op[0](ba);
	else
		op[i % 3 ? 2 : 1](ba);
}

void				ft_put_sol(unsigned int i)
{
	if (i / 3)
		ft_put_sol(i / 3);
	i %= 3;
	if (i == 0)
		ft_putstr("sa ");
	else if (i == 1)
		ft_putstr("ra ");
	else if (i == 2)
		ft_putstr("rra ");
}

void				call_algo(t_swap **ba, t_swap **bb)
{
	void			*tmp;
	unsigned int	i;

	tmp = ft_pt_op();
	i = 0;

	ft_algo(tmp, ba, bb, i);
	while (!ft_sorted(*ba))
	{
		ft_algo_remove(tmp, ba, bb, i);
		ft_algo(tmp, ba, bb, ++i);
		ft_putnbr(i);
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
	ft_putstr("*********************************************\n\n\n\n\n");
	ft_putstr("*********************************************\n\n\n\n\n");
	if (ft_sorted(ba))
		return (0);
	call_algo(&ba, &bb);
	ft_print_list(ba);
	return (0);
}
