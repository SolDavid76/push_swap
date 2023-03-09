/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:41:28 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/09 14:11:55 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*tmp;

	if (ac == 1)
		return (1);
	lst = parsing(av + 1);
	if (!lst)
		return (1);
	sa(lst);
	tmp = lst;
	while (lst)
	{
		dprintf(1, "%li\n", lst->content);
		lst = lst->next;
	}
	ft_lst_free(tmp);
}
