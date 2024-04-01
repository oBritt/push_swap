/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:51:18 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:06:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void		errors(void);
int			check_argv(int *temp, char ***s);
int			check_unique(int *temp, int len);
int			push_swap(int *temp, int len);
void		set_to_zero(int	*array);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst);
t_list		*reverse(t_list *head);
int			len_lst(t_list *head);
t_list		*create(int	*temp, int len);

//alg 2
int			saver_lines(t_list **a);
int			solve2(t_list **a, t_list **b, int len);
int			check_if_sorted_alg(t_list **a);
t_list		*find_min(t_list *a);
t_list		*find_max(t_list *a);
int			outputting(t_list **a, t_list **b, int *out);
void		set_to_zero_ind(int *array, int ind);
void		set_to_max(int *array, int ind);
int			*make_best(int ind_a, int ind_b, int len_a, int len_b);
void		better(int *current, int *out);
int			min(int a, int b);
int			alg_send_to_b(t_list **a, t_list **b, int *min, int *max);
int			find_by_value_lst(t_list *t, int value);
int			remaining(t_list **a, t_list **b);
int			get_ind(int num, t_list **b, int *min, int *max);
int			check_if_sorted(t_list *head, int len, int inc);
t_list		*sorting(t_list *head, int inc);
t_list		*merge_d(t_list *first, t_list *second);
t_list		*ft_lstmap_in(t_list *lst, int len);
char		**ft_split(char const *s, char c);
void		freeings(char **words, int len);
char		***ft_splitter(int argc, char **argv);
int			get_len_s(char ***s);
void		deleting_all(char ***s, int len);

int			sa(t_list **a, int i);
int			sb(t_list **a, int i);
int			ss(t_list **a, t_list **b, int i);
int			pa(t_list **a, t_list **b, int i);
int			pb(t_list **a, t_list **b, int i);
int			ra(t_list **a, int i);
int			rb(t_list **b, int i);
int			rr(t_list **a, t_list **b, int i);
int			rra(t_list	**a, int i);
int			rrb(t_list **b, int i);
int			rrr(t_list **a, t_list **b, int i);
#endif