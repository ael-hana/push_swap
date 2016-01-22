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
	//while ((i-- + 1) > 0)
	//	(i + 1) ? ft_putstr("pb ") : ft_putstr("pb");
	return (1);
}

void		ft_print_list(t_swap *ptr)
{
	while (ptr->next)
	{
		printf("\nla data est %d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("la data est %d\n", ptr->data);
}

void		ft_algo(t_swap **ba, t_swap **bb)
{
	void	*tmp;

	while (!ft_sorted(*ba))
	{
		if (*ba && (tmp = sa(*ba)))
			*ba= tmp;
		else
		{
			ra(ba);
			ra(ba);
		}
		ft_putchar(' ');
	}
}

int			main(int ac, char **av)
{
	t_swap	*ba;
	t_swap	*bb;

	bb = NULL;
	ft_check_params(ac, av);
	ba = ft_creat_list(ac - 1, av);
	if (ft_sorted(ba))
		return (0);
	ft_algo(&ba, &bb);
	ft_print_list(ba);
	return (0);
}
