/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:05:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:31:58 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_list **start_a, t_list **start_b)
{
	t_list	*a;

	a = *start_a;
	if (ft_lst_is_sorted(a) || short_sort(start_a, start_b))
		return ;
}
