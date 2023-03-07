/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:42:23 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/07 03:30:17 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //plz remove before push

typedef struct s_list
{
	long int		content;
	struct s_list	*next;
}					t_list;

/* utils.c */
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
long int	ft_atol(char *str);
void		free_tab(char **tab);
char		**ft_split(char *str, char c);

/* parsing.c */
t_list		*parsing(char **av);
int			ft_lst_check_content(t_list *lst);

/* lst.c */
t_list		*ft_lstnew(long int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lst_free(t_list	*lst);

#endif
