/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:59:11 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 11:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void print_program_headers_x64(Elf64_Ehdr *header, Elf64_Phdr *seg_headers)
{
	printf("\n\n	==== PROGRAM HEADER TABLE ====\n");
	printf("(Index|Type|FLAGS|Offset|Virtual addr|Physical addr|Size in file|Size in memory|Alignment)\n\n");

	for (int i = 0; i < header->e_phnum; i++)
	{
		printf("> %3i | ", i);
		switch(seg_headers[i].p_type)
		{
			case(PT_NULL):
				printf("%15s", "PT_NULL");
				break;
			case(PT_LOAD):
				printf("%15s", "PT_LOAD");
				break;
			case(PT_DYNAMIC):
				printf("%15s", "PT_DYNAMIC");
				break;
			case(PT_INTERP):
				printf("%15s", "PT_INTERP");
				break;
			case(PT_NOTE):
				printf("%15s", "PT_NOTE");
				break;
			case(PT_SHLIB):
				printf("%15s", "PT_SHLIB");
				break;
			case(PT_PHDR):
				printf("%15s", "PT_PHDR");
				break;
			case(PT_TLS):
				printf("%15s", "PT_TLS");
				break;
			case(PT_NUM):
				printf("%15s", "PT_NUM");
				break;
			case(PT_GNU_EH_FRAME):
				printf("%15s", "PT_GNU_EH_FRAME");
				break;
			case(PT_GNU_STACK):
				printf("%15s", "PT_GNU_STACK");
				break;
			case(PT_GNU_RELRO):
				printf("%15s", "PT_GNU_RELRO");
				break;
			default:
				printf("%15s", "unknown");
				break;
		}

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
}
