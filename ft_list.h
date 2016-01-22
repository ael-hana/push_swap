/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:04:02 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/22 14:52:57 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_swap
{
	int					data;
	struct s_swap		*next;
}						t_swap;
void					ft_check_int(char *av);
void					ft_check_overflow(char *av);
unsigned char			ft_check_params(int ac, char **av);
void					ft_error();
t_swap					*ft_init_list(char *av);
t_swap					*ft_creat_list(int max, char **av);
void					ft_print_list(t_swap *ptr);
void					ft_ss(t_swap **ptr, t_swap **ptr2);
t_swap					*sb(t_swap *ptr);
void					pa(t_swap **ptr, t_swap **ptr2);
void					ft_rotate(t_swap **ptr);
t_swap					*sa(t_swap *ptr);
t_swap					*sb(t_swap *ptr);
void					ra(t_swap **ptr);
void					rb(t_swap **ptr);
void					rr(t_swap **ptr, t_swap **ptr2);
void					ft_rev_rotate(t_swap **ptr);
void					rra(t_swap **ptr);
void					rrb(t_swap **ptr);
void					rrr(t_swap **ptr, t_swap **ptr2);
