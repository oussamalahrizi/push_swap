/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:53:10 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/17 02:39:29 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stuff2(t_vars *vars, int ac, char **av)
{
	vars->size = get_array_size(ac, av);
	vars->init_array = (int *)malloc(sizeof(int) * vars->size);
	fill_array(ac, av, vars->init_array);
	check_duplicates(vars->init_array, vars->size);
	fill_stack_a(&vars->a, vars->init_array, vars->size);
}

int	check_stack_sorted(t_list **a)
{
	t_list	*head;

	head = *a;
	while (head->next && head->content < head->next->content)
		head = head->next;
	if (!head->next)
		return (1);
	return (0);
}

void	do_moves(char *move, t_vars *vars)
{
	if (!ft_strncmp(move, SA, ft_strlen(SA)))
		swap_first_2(&vars->a, NULL);
	else if (!ft_strncmp(move, SB, ft_strlen(SB)))
		swap_first_2(&vars->b, NULL);
	else if (!ft_strncmp(move, SS, ft_strlen(SS)))
		ss(&vars->a, &vars->b, 0);
	else if (!ft_strncmp(move, PA, ft_strlen(PA)))
		pa(&vars->a, &vars->b, 0);
	else if (!ft_strncmp(move, PB, ft_strlen(PB)))
		pb(&vars->a, &vars->b, 0);
	else if (!ft_strncmp(move, RA, ft_strlen(RA)))
		rotate(&vars->a, NULL);
	else if (!ft_strncmp(move, RB, ft_strlen(RB)))
		rotate(&vars->b, NULL);
	else if (!ft_strncmp(move, RR, ft_strlen(RR)))
		rr(&vars->a, &vars->b, 0);
	else if (!ft_strncmp(move, RRA, ft_strlen(RRA)))
		reverse_rotate(&vars->a, NULL);
	else if (!ft_strncmp(move, RRB, ft_strlen(RRB)))
		reverse_rotate(&vars->b, NULL);
	else if (!ft_strncmp(move, RRR, ft_strlen(RRR)))
		rrr(&vars->a, &vars->b, 0);
	else
		p_error();
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*move;

	vars.a = NULL;
	vars.b = NULL;
	if (ac > 1)
	{
		init_stuff2(&vars, ac, av);
		move = get_next_line(0);
		while (move)
		{
			if (!ft_strncmp(move, "\n", ft_strlen("\n")))
				break ;
			do_moves(move, &vars);
			free(move);
			move = get_next_line(0);
		}
		if (check_stack_sorted(&vars.a) == 1 && !ft_lstsize(vars.b)
			&& ft_lstsize(vars.a) == vars.size)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
