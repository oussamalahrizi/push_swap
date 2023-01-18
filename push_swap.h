/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:11:25 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 12:49:54 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_helper
{
	int		start;
	int		end;
	int		middle;
	int		array_size;
	int		chunk_size;
}			t_helper;

typedef struct s_vars
{
	t_list	*a;
	t_list	*b;
	int		*init_array;
	int		size;
}			t_vars;

void		swap_first_2(t_list **list, char *str);
void		ss(t_list **a, t_list **b, int flag);
void		pa(t_list **a, t_list **b, int flag);
void		pb(t_list **a, t_list **b, int flag);
void		rotate(t_list **list, char *str);
void		rr(t_list **a, t_list **b, int flag);
void		reverse_rotate(t_list **list, char *str);
void		rrr(t_list **a, t_list **b, int flag);
void		p_error(void);
void		sort_three(t_list **stack);
void		sort_five(t_list **a, t_list **b, int *array, int size);
void		sort_int_tab(int *tab, int size);
void		check_duplicates(int *tab, int size);
int			get_min(t_list **a, int *tab, int pos);
int			get_array_size(int ac, char **av);
void		fill_array(int ac, char **av, int *array);
void		fill_stack_a(t_list **a, int *array, int size);
void		update_params(t_helper *helper);
void		init_helper(t_helper *helper, int size);
void		init_stuff(t_vars *vars, int ac, char **av);
int			search_content(t_list **a, int find);
int			max_in_b(t_list **b, int max);

#endif