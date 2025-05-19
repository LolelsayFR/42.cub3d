/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:01 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 11:34:14 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

char	**lst_to_tab(t_list *lst)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	while (lst != NULL)
	{
		tab[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
