/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:54:09 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 12:49:01 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_2(t_list **list, char *str)
{
	int		temp;
	t_list	*node;

	node = *list;
	if (ft_lstsize(*list) > 1)
	{
		temp = node->content;
		node->content = node->next->content;
		node->next->content = temp;
		if (str)
			ft_putstr_fd(str, 1);
	}
}

void	ss(t_list **a, t_list **b, int flag)
{
	swap_first_2(a, NULL);
	swap_first_2(b, NULL);
	if (flag)
		ft_putstr_fd("ss", 1);
}

void	pa(t_list **a, t_list **b, int flag)
{
	t_list	*head;

	if (ft_lstsize(*b))
	{
		head = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, ft_lstnew(head->content));
		free(head);
		if (flag)
			ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_list **a, t_list **b, int flag)
{
	t_list	*head;

	if (ft_lstsize(*a))
	{
		head = *a;
		ft_lstadd_front(b, ft_lstnew(head->content));
		*a = (*a)->next;
		free(head);
		if (flag)
			ft_putstr_fd("pb\n", 1);
	}
}

void	rotate(t_list **list, char *str)
{
	t_list	*head;
	t_list	*last;
	t_list	*second;

	if (ft_lstsize(*list) <= 1)
		return ;
	head = *list;
	second = head->next;
	last = ft_lstlast(head);
	head->next = NULL;
	last->next = head;
	*list = second;
	if (str)
		ft_putstr_fd(str, 1);
}
