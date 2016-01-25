/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:10:42 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/25 05:56:37 by ael-hana         ###   ########.fr       */
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

void		ft_print_list(t_swap *ptr, int op)
{
	if (op)
	{
		ft_putstr("\n*********************************************************");
		ft_putstr("\na :");
	}
	else
		ft_putstr("\nb :");
	while (ptr && ptr->next)
	{
		ft_putstr(" ");
		ft_putnbr(ptr->data);
		ptr = ptr->next;
	}
	ft_putstr(" ");
	if (ptr)
		ft_putnbr(ptr->data);
	if (!op)
		ft_putstr("\n*********************************************************\n");
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

void				call_algo(t_swap **ba, t_swap **bb, int ac, char **av)
{
	void			*tmp;
	void			**dup;
	unsigned int	i;

	*bb = NULL;
	tmp = ft_pt_op();
	i = 0;
	if (ac > 6 && !ft_sorted(*ba))
		return (ft_algo_sort_s(tmp, ba, !ft_strcmp(av[1], "-v") ? 1 : 0));
	ft_algo(tmp, ba, bb, i);
	while (!*ba || !ft_sorted(*ba) || *bb)
	{
		*ba = ft_creat_list(ac, av);
		*bb = NULL;
		ft_algo(tmp, ba, bb, ++i);
	}
	*ba = ft_creat_list(ac, av);
	*bb = NULL;
	ft_put_sol(i, !ft_strcmp(av[1], "-v") ? 1 : 0, ba, bb);
	ft_putchar('\n');
}

int			main(int ac, char **av)
{
	t_swap	*ba;
	t_swap	*bb;
	int		op;

	op = ft_check_params(ac, av);
	ba = ft_creat_list(ac - 1, av);
	if (op)
	{
		if (ft_sorted(ba))
			ft_putstr("fini");
		ft_print_list(ba, 1);
		ft_print_list(bb, 0);
	}
	if (ft_sorted(ba))
		return (0);
	call_algo(&ba, &bb, (ac - 1), av);
	if (op)
	{
		ft_putstr("fini");
		ft_print_list(ba, 1);
		ft_print_list(bb, 0);
	}
	return (0);
}
