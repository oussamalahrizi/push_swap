/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:12:30 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:05 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra(t_list **a, t_list **b, int *array, t_helper *helper)
{
	t_list	*head;

	head = *a;
	(void)b;
	while (head && !(head->content >= array[helper->start]
			&& head->content <= array[helper->end]))
		head = head->next;
	if (!head)
		update_params(helper);
	else
	{
		if (search_content(a, head->content) <= ft_lstsize(*a) / 2)
			rotate(a, "ra\n");
		else
			reverse_rotate(a, "rra\n");
	}
}

void	push_to_b(t_list **a, t_list **b, t_helper *helper, int *array)
{
	while (*a)
	{
		if ((*a)->content >= array[helper->start]
			&& (*a)->content <= array[helper->end])
		{
			pb(a, b, 1);
			if ((*b)->content < array[helper->middle])
				rotate(b, "rb\n");
		}
		else
			ra_rra(a, b, array, helper);
	}
}

void	push_to_a_helper(t_vars *vars, int *down)
{
	if ((vars->b->content) == vars->init_array[vars->size])
	{
		pa(&vars->a, &vars->b, 1);
		vars->size--;
	}
	else
	{
		if (!*down || (vars->b->content) > ft_lstlast(vars->a)->content)
		{
			pa(&vars->a, &vars->b, 1);
			rotate(&vars->a, "ra\n");
			++*down;
		}
		else
		{
			if (search_content(&vars->b,
					vars->init_array[vars->size]) <= ft_lstsize(vars->b) / 2)
				rotate(&vars->b, "rb\n");
			else
				reverse_rotate(&vars->b, "rrb\n");
		}
	}
}

void	push_to_a(t_vars *vars)
{
	int	down;

	down = 0;
	while (vars->b)
	{
		if (max_in_b(&vars->b, vars->init_array[vars->size]))
			push_to_a_helper(vars, &down);
		else
		{
			reverse_rotate(&vars->a, "rra\n");
			down--;
			vars->size--;
		}
	}
	while (down--)
		reverse_rotate(&vars->a, "rra\n");
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_helper	helper;

	vars.a = NULL;
	vars.b = NULL;
	if (ac > 1)
	{
		init_stuff(&vars, ac, av);
		if (vars.size == 2)
			swap_first_2(&vars.a, "sa\n");
		else if (vars.size == 3)
			sort_three(&vars.a);
		else if (vars.size <= 5)
			sort_five(&vars.a, &vars.b, vars.init_array, vars.size);
		else
		{
			init_helper(&helper, vars.size);
			push_to_b(&vars.a, &vars.b, &helper, vars.init_array);
			vars.size--;
			push_to_a(&vars);
		}
	}
	return (0);
}
