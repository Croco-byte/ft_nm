/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:00:30 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 15:07:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_class(uint8_t flag)
{
	if (flag == ELFCLASS32)
		printf("ELF32");
	else if (flag == ELFCLASS64)
		printf("ELF64");
	else
		printf("Invalid");
}

void	print_machine(uint16_t flag)
{
	if (flag == EM_NONE)
		printf("None");
	else if (flag == EM_SPARC)
		printf("SPARC");
	else if (flag == EM_386)
		printf("Intel x86");
	else if (flag == EM_PPC64)
		printf("PowerPC 64");
	else if (flag == EM_ARM)
		printf("ARM");
	else if (flag == EM_x86_64)
		printf("Advanced Micro Devices X86-64");
	else
		printf("Unknown");
}
