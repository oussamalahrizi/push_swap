/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:42:47 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 11:34:21 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			count++;
			i = 0;
		}
		else
			i++;
	}
	if (!count)
		exit(0);
}

void	check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				p_error();
			j++;
		}
		i++;
	}
}

int	get_min(t_list **a, int *tab, int pos)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *a;
	while (head)
	{
		if (head->content == tab[pos])
			return (i);
		i++;
		head = head->next;
	}
	return (0);
}

int	get_array_size(int ac, char **av)
{
	int		i;
	int		j;
	char	**temp;
	int		size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		temp = ft_split(av[i], ' ');
		if (!temp[0])
			p_error();
		while (temp[j])
		{
			free(temp[j]);
			j++;
			size++;
		}
		i++;
		free(temp);
	}
	return (size);
}

void	fill_array(int ac, char **av, int *array)
{
	int		i;
	int		j;
	int		size;
	char	**temp;

	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		temp = ft_split(av[i], ' ');
		while (temp[j])
		{
			array[size] = ft_atoi(temp[j]);
			free(temp[j]);
			j++;
			size++;
		}
		i++;
		free(temp);
	}
}
