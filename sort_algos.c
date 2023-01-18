/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:16:32 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:47 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		swap_first_2(stack, "sa\n");
	else if ((*stack)->content > (*stack)->next->next->content
		&& (*stack)->content > (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		swap_first_2(stack, "sa\n");
		reverse_rotate(stack, "rra\n");
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content)
		rotate(stack, "ra\n");
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		swap_first_2(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if ((*stack)->content > (*stack)->next->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
		reverse_rotate(stack, "rra\n");
}

void	helper_five(int pos, t_list **a)
{
	if (pos >= ft_lstsize(*a) / 2)
	{
		while (pos < ft_lstsize(*a))
		{
			reverse_rotate(a, "rra\n");
			pos++;
		}
	}
	else
		while (pos--)
			rotate(a, "ra\n");
}

void	sort_five(t_list **a, t_list **b, int *array, int size)
{
	int	pos;

	pos = get_min(a, array, 0);
	helper_five(pos, a);
	pb(a, b, 1);
	if (size == 5)
	{
		pos = get_min(a, array, 1);
		helper_five(pos, a);
		pb(a, b, 1);
	}
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
