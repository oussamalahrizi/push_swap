/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:34:17 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/17 02:39:23 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_helper(t_helper *helper, int size)
{
	if (size <= 10)
		helper->chunk_size = size / 5;
	else if (size <= 150)
		helper->chunk_size = size / 8;
	else
		helper->chunk_size = size / 18;
	helper->middle = size / 2;
	helper->start = helper->middle - helper->chunk_size;
	helper->end = helper->middle + helper->chunk_size;
	helper->array_size = size;
}

void	init_stuff(t_vars *vars, int ac, char **av)
{
	vars->size = get_array_size(ac, av);
	vars->init_array = (int *)malloc(sizeof(int) * vars->size);
	fill_array(ac, av, vars->init_array);
	check_duplicates(vars->init_array, vars->size);
	fill_stack_a(&vars->a, vars->init_array, vars->size);
	sort_int_tab(vars->init_array, vars->size);
}

void	update_params(t_helper *helper)
{
	helper->start -= helper->chunk_size;
	helper->end += helper->chunk_size;
	if (helper->start < 0)
		helper->start = 0;
	if (helper->end > helper->array_size - 1)
		helper->end = helper->array_size - 1;
}

int	search_content(t_list **a, int find)
{
	t_list	*head;
	int		i;

	head = *a;
	i = 0;
	while (head)
	{
		if (head->content == find)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

int	max_in_b(t_list **b, int max)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *b;
	while (head)
	{
		if (head->content == max)
			return (1);
		head = head->next;
	}
	return (0);
}
