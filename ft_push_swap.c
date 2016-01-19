/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:10:42 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/19 20:46:22 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_error()
{
	exit(EXIT_FAILURE);
}

t_list		*ft_init_list(int max, int i, char *av, t_list *next)
{
	t_list	*ptr;


	if (!(ptr = malloc(sizeof(t_list))))
		ft_error();
	ptr->next = next;
	ptr->max = max;
	ptr->data = av;
	ptr->i = i;
	return (ptr);
}

t_list		*ft_creat_list(int max, char **av)
{
	int		i;
	void	*save;
	t_list	*ptr;

	i = 2;
	ptr = ft_init_list(max, 1, av[1], NULL);
	save = ptr;
	while (i <= max)
	{
		ptr->next = ft_init_list(max, i, av[i], save);
		ptr = ptr->next;
		++i;
	}
	return (ptr->next);
}

void	ft_print_list(t_list *ptr)
{
	while (ptr->max > ptr->i)
	{
		printf("le max est : %d, le i est %d, la data est %s\n", ptr->max, ptr->i, ptr->data);
		ptr = ptr->next;
	}
	printf("le max est : %d, le i est %d, la data est %s\n", ptr->max, ptr->i, ptr->data);
}

int		main(int ac, char **av)
{

	if (ac > 1)
		ft_print_list(ft_creat_list(ac - 1, av));
	return (0);
}
