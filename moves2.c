/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:30:41 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 12:49:30 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b, int flag)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (flag)
		ft_putstr_fd("rr", 1);
}

void	reverse_rotate(t_list **list, char *str)
{
	t_list	*b_last;
	t_list	*last;
	t_list	*head;

	if (ft_lstsize(*list) <= 1)
		return ;
	last = ft_lstlast(*list);
	b_last = *list;
	head = *list;
	while (b_last)
	{
		if (b_last->next->next == NULL)
			break ;
		b_last = b_last->next;
	}
	last->next = head;
	b_last->next = NULL;
	*list = last;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rrr(t_list **a, t_list **b, int flag)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	if (flag)
		ft_putstr_fd("rrr", 1);
}

void	p_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}
