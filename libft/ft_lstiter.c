/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:45:22 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/14 21:14:45 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

// void f(void *content)
// {
// 	while (*(char *)content)
// 	{
// 		++*(char *)content;
// 		content++;
// 	}
// }

// int main (void)
// {
// 	char str[4] = "aaa";
// 	t_list	*head = ft_lstnew(str);
// 	printf("%s\n", head->content);
// 	ft_lstiter(head, f);
// 	printf("%s\n", head->content);
// }