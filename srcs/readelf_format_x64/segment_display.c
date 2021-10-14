/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:59:11 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 10:54:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	segment_part_1_x64(Elf64_Phdr *seg_headers, int i)
{
	printf("> %3i | ", i);
	if (seg_headers[i].p_type == PT_NULL)
		printf("%15s", "PT_NULL");
	else if (seg_headers[i].p_type == PT_LOAD)
		printf("%15s", "PT_LOAD");
	else if (seg_headers[i].p_type == PT_DYNAMIC)
		printf("%15s", "PT_DYNAMIC");
	else if (seg_headers[i].p_type == PT_INTERP)
		printf("%15s", "PT_INTERP");
	else if (seg_headers[i].p_type == PT_NOTE)
		printf("%15s", "PT_NOTE");
	else if (seg_headers[i].p_type == PT_SHLIB)
		printf("%15s", "PT_SHLIB");
	else if (seg_headers[i].p_type == PT_PHDR)
		printf("%15s", "PT_PHDR");
	else if (seg_headers[i].p_type == PT_TLS)
		printf("%15s", "PT_TLS");
	else if (seg_headers[i].p_type == PT_NUM)
		printf("%15s", "PT_NUM");
	else if (seg_headers[i].p_type == PT_GNU_EH_FRAME)
		printf("%15s", "PT_GNU_EH_FRAME");
	else if (seg_headers[i].p_type == PT_GNU_STACK)
		printf("%15s", "PT_GNU_STACK");
	else if (seg_headers[i].p_type == PT_GNU_RELRO)
		printf("%15s", "PT_GNU_RELRO");
}

void	segment_part_2_x64(Elf64_Phdr *seg_headers, int i)
{
	printf(" | ");
	if (seg_headers[i].p_flags & PF_R)
		printf("%s", "R");
	if (seg_headers[i].p_flags & PF_W)
		printf("%s", "W");
	if (seg_headers[i].p_flags & PF_X)
		printf("%s", "E");
	printf("	| ");
	printf("0x%08lx", seg_headers[i].p_offset);
	printf(" | ");
	printf("0x%08lx", seg_headers[i].p_vaddr);
	printf(" | ");
	printf("0x%08lx", seg_headers[i].p_paddr);
	printf(" | ");
	printf("0x%08lx", seg_headers[i].p_filesz);
	printf(" | ");
	printf("0x%08lx", seg_headers[i].p_memsz);
	printf(" | ");
	printf("0x%lx\n", seg_headers[i].p_align);
}

void	readelf_progheaders_x64(Elf64_Ehdr *header, Elf64_Phdr *seg_headers)
{
	int		i;

	i = -1;
	printf("\n\n	==== PROGRAM HEADER TABLE ====\n");
	printf("(Index|Type|FLAGS|Offset|Virtual addr|Physical addr");
	printf("|Size in file|Size in memory|Alignment)\n\n");
	while (++i < header->e_phnum)
	{
		segment_part_1_x64(seg_headers, i);
		segment_part_2_x64(seg_headers, i);
	}
}
