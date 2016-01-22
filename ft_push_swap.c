/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:10:42 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 03:37:45 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_error()
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

void	ft_print_list(t_swap *ptr)
{
	while (ptr->next)
	{
		printf("la data est %d\n", ptr->data);
		ptr = ptr->next;
	}
		printf("la data est %d\n", ptr->data);
}

int		main(int ac, char **av)
{
	t_swap	*ba;
	t_swap	*bb;

	bb = NULL;
	ft_check_params(ac, av);
	ba = ft_creat_list(ac - 1, av);
	//ba = ft_sa(ba);
	pa(&ba, &bb);
	ft_print_list(ba);
	ft_print_list(bb);
	return (0);
}
