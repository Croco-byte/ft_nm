/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:14:41 by user42            #+#    #+#             */
/*   Updated: 2021/10/11 17:15:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	swap_symbols_x32(SymHolder32 *first, SymHolder32 *second)
{
	SymHolder32	temp;
	temp.skip = first->skip;
	temp.value = first->value;
	temp.type = first->type;
	temp.name = first->name;
	first->skip = second->skip;
	first->value = second->value;
	first->type = second->type;
	first->name = second->name;
	second->skip = temp.skip;
	second->value = temp.value;
	second->type = temp.type;
	second->name = temp.name;
}

void	sort_symbols_x32(SymHolder32 *holders, int sym_num)
{
	for(int j=1; j < sym_num; j++)
	{
		for (int i=j+1; i < sym_num; i++)
		{
			if (holders[j].name[0] != '\0' && holders[i].name[0] != '\0' && ft_strcmp(holders[j].name, holders[i].name) > 0)
				swap_symbols_x32(&holders[j], &holders[i]);
			if (holders[j].name[0] != '\0' && holders[i].name[0] != '\0' && ft_strcmp(holders[j].name, holders[i].name) == 0 && holders[i].value < holders[j].value)
				swap_symbols_x32(&holders[j], &holders[i]);
		}
	}
}
