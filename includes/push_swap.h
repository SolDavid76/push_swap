/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:42:23 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:36:01 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //plz remove before push

typedef struct s_list
{
	long int		content;
	struct s_list	*next;
}					t_list;

/* utils.c */
int			ft_strlen(char *str);
char		*ft_calloc(int size);
char		*ft_strjoin(char *s1, char *s2);
long int	ft_atol(char *str);
void		free_tab(char **tab);
char		**ft_split(char *str, char c);

/* parsing.c */
t_list		*parsing(char **av);
t_list		*listing(char **tab);
int			ft_lst_check_content(t_list *lst);

/* lst.c */
t_list		*ft_lstnew(long int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lst_free(t_list	*lst);
void		ft_lst_print(t_list *lst, char c);
int			ft_lst_is_sorted(t_list *lst);
t_list		*ft_lst_max(t_list *lst);
t_list		*ft_lst_min(t_list *lst);
t_list		*ft_lst_median(t_list *lst);
int			ft_lst_index(t_list *lst, t_list *elem);

/* move.c */
void		swap_ab(t_list **start, char c);
void		swap(t_list **start_a, t_list **start_b);
void		push(t_list **start_src, t_list **start_dst, char c);
void		rotate_ab(t_list **start, char c);
void		rotate(t_list **start_a, t_list **start_b); 
void		rrotate_ab(t_list **start, char c);
void		rrotate(t_list **start_a, t_list **start_b);

/* sorting.c */
void		push_elem(t_list **start_s, t_list **start_d, t_list *elem, char c);
int			short_sort(t_list **start_a, t_list **start_b);
void		ft_sorting(t_list **start_a, t_list **start_b);

/* estim.c */
int			estim_rotate(t_list *lst, t_list *elem);
int			estim_rrotate(t_list *lst, t_list *elem);
int			estim_move(t_list *lst, t_list *x);
int			estim(t_list *lst, t_list *x);
t_list		*best_elem(t_list *lst_a, t_list *lst_b);

#endif
