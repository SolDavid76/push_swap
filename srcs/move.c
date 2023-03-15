/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:35:08 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 16:47:01 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **start, char c)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *start;
	tmp = lst->next;
	lst->next = lst->next->next;
	tmp->next = lst;
	*start = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	swap(t_list **start_a, t_list **start_b)
{
	swap_ab(start_a, '\0');
	swap_ab(start_b, '\0');
	write(1, "ss\n", 3);
}

void	push(t_list **start_src, t_list **start_dst, char c)
{
	t_list	*src;
	t_list	*dst;

	src = *start_src;
	dst = *start_dst;
	*start_dst = dst->next;
	dst->next = src;
	*start_src = dst;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}
