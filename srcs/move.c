/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:35:08 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/13 16:31:12 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_ab(t_list *lst, unsigned char c)
{
	t_list	*tmp;

	tmp = lst->next;
	lst->next = lst->next->next;
	tmp->next = lst;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	return (tmp);
}

void	swap(t_list **start_a, t_list **start_b)
{
	*start_a = swap_ab(*start_a, '\0');
	*start_b = swap_ab(*start_b, '\0');
	write(1, "ss\n", 3);
}

void	push_ab(t_list **start_a, t_list **start_b, unsigned char c)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	if (c == 'a')
	{
		*start_b = b->next;
		b->next = a;
		*start_a = b;
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		*start_a = a->next;
		a->next = b;
		*start_b = a;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_list **start_a, t_list **start_b, unsigned char c)
{
	t_list	*lst;

	if (c == 'a' || c == 'a' + 'b')
	{
		lst = *start_a;
		*start_a = lst->next;
		ft_lstlast(lst)->next = lst;
		lst->next = NULL;
		if (c == 'a')
			write(1, "ra\n", 3);
	}
	if (c == 'b' || c == 'a' + 'b')
	{
		lst = *start_b;
		*start_b = lst->next;
		ft_lstlast(lst)->next = lst;
		lst->next = NULL;
		if (c == 'b')
			write(1, "rb\n", 3);
	}
	if (c == 'a' + 'b')
		write(1, "rr\n", 3);
}

// /* Function has more than 25 lines */
// void	rrotate(t_list **start_a, t_list **start_b, unsigned char c)
// {
// 	t_list	*last;
// 	t_list	*lst;

// 	if (c == 'a' || c == 'a' + 'b')
// 	{
// 		lst = *start_a;
// 		last = ft_lstlast(lst);
// 		while (lst->next != last)
// 			lst = lst->next;
// 		lst->next = NULL;
// 		last->next = *start_a;
// 		*start_a = last;
// 		if (c == 'a')
// 			write(1, "rra\n", 4);
// 	}
// 	if (c == 'b' || c == 'a' + 'b')
// 	{
// 		lst = *start_b;
// 		last = ft_lstlast(lst);
// 		while (lst->next != last)
// 			lst = lst->next;
// 		lst->next = NULL;
// 		last->next = *start_b;
// 		*start_b = last;
// 		if (c == 'b')
// 			write(1, "rra\n", 4);
// 	}
// 	if (c == 'a' + 'b')
// 		write(1, "rrr\n", 4);
// }
