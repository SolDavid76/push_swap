/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:09:59 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/11 11:08:28 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content < lst->next->content)
			reutrn (1);
		lst = lst->next;
	}
	return (0);
}

int main