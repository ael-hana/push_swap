/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:04:02 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/21 23:08:49 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_swap
{
	int					i;
	unsigned int		max;
	int					data;
	struct s_swap		*previous;
	struct s_swap		*next;
}						t_swap;
void					ft_check_int(char *av);
void					ft_check_overflow(char *av);
unsigned char			ft_check_params(int ac, char **av);
void					ft_error();
t_swap					*ft_init_list(int max, int i, char *av, t_swap *next);
t_swap					*ft_creat_list(int max, char **av);
void					ft_print_list(t_swap *ptr);
void					ft_sa(t_swap *ptr);
