/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:04:02 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/20 20:13:44 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_swap
{
	int					i;
	char				branch;
	unsigned int		max;
	int					data;
	struct s_swap		*next;
}						t_swap;

unsigned char	ft_check_params(int ac, char **av);
void		ft_error();
