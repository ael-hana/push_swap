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

void		ft_algo(t_swap **ba, t_swap **bb)
{
	t_swap	*tmp;
	int		i;
	int		max;
	int		stop = 4200;

	tmp = *ba;
	max = 0;
	if (ft_size_list(*ba) > 3)
	{
		while (tmp)
		{
			if (max < tmp->data)
				max = tmp->data;
			tmp = tmp->next;
		}
		tmp = *ba;
		while (tmp->data != max)
		{
			++i;
			tmp = tmp->next;
		}
		while (((ft_size_list(*ba) / 2) < i) && --i)
			ra(ba);
		while ((*ba)->data != max)
			rra(ba);
	}
	while (!ft_sorted(*ba) && stop)
	{
		if (*ba && (tmp = sa(*ba))) // sa
			*ba = tmp;
		else
			rra(ba);
			--stop;
		ft_putchar(' ');
		ft_putstr("*********************************************\n\n\n\n\n");
		ft_print_list(*ba);
		ft_putstr("*********************************************\n\n\n\n\n");
	}
	if (!stop)
		ft_error();
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
	ft_algo(&ba, &bb);
	ft_print_list(ba);
	return (0);
}
