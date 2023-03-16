/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:41:28 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:04:30 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_print(t_list *lst, char c)
{
	printf("%c = ", c);
	while (lst)
	{
		printf("%li, ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac == 1)
		return (1);
	lst_a = parsing(av + 1);
	lst_b = NULL;
	if (!lst_a)
		return (1);
	ft_sorting(&lst_a, &lst_b);
	// push(&lst_a, &lst_b, 'b');
	if (ft_lst_is_sorted(lst_a))
		write(1, "sorted\n", 7);
	else
		write(1, "not sorted\n", 11);
	ft_lst_print(lst_a, 'a');
	ft_lst_print(lst_b, 'b');
	ft_lst_free(lst_a);
	ft_lst_free(lst_b);
}
