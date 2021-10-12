/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:01:16 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 12:54:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_section_headers_x64(Elf64_Ehdr *header, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer)
{
	printf("\n\n	==== SECTION HEADER TABLE ====\n");
	printf("(Index|Name|Type|Flags|Addr|Offset|Size|Links|Info|Alignment|Entry Size)\n\n");

	for (int i = 0; i < header->e_shnum; i++)
	{
		printf("> %3i | ", i);
		printf("%18s | ", (sec_strtab_pointer + sec_headers[i].sh_name));
		switch(sec_headers[i].sh_type)
		{
			case(SHT_NULL):
				printf("%15s", "NULL");
				break;
			case(SHT_PROGBITS):
				printf("%15s", "PROGBITS");
				break;
			case(SHT_SYMTAB):
				printf("%15s", "SYMTAB");
				break;
			case(SHT_STRTAB):
				printf("%15s", "STRTAB");
				break;
			case(SHT_RELA):
				printf("%15s", "RELA");
				break;
			case(SHT_HASH):
				printf("%15s", "HASH");
				break;
			case(SHT_DYNAMIC):
				printf("%15s", "DYNAMIC");
				break;
			case(SHT_NOTE):
				printf("%15s", "NOTE");
				break;
			case(SHT_NOBITS):
				printf("%15s", "NOBITS");
				break;
			case(SHT_REL):
				printf("%15s", "REL");
				break;
			case(SHT_SHLIB):
				printf("%15s", "SHLIB");
				break;
			case(SHT_DYNSYM):
				printf("%15s", "DYNSYM");
				break;
			case(SHT_INIT_ARRAY):
				printf("%15s", "INIT_ARRAY");
				break;
			case(SHT_FINI_ARRAY):
				printf("%15s", "FINI_ARRAY");
				break;
			case(SHT_PREINIT_ARRAY):
				printf("%15s", "PREINIT_ARRAY");
				break;
			case(SHT_GROUP):
				printf("%15s", "GROUP");
				break;
			case(SHT_SYMTAB_SHNDX):
				printf("%15s", "SYMTAB_SHNDX");
				break;
			case(SHT_NUM):
				printf("%15s", "NUM");
				break;
			case(SHT_LOOS):
				printf("%15s", "LOOS");
				break;
			case(SHT_GNU_ATTRIBUTES):
				printf("%15s", "GNU_ATTRIBUTES");
				break;
			case(SHT_GNU_HASH):
				printf("%15s", "GNU_HASH");
				break;
			case(SHT_GNU_LIBLIST):
				printf("%15s", "GNU_LIBLIST");
				break;
			case(SHT_GNU_verdef):
				printf("%15s", "GNU_VERDEF");
				break;
			case(SHT_GNU_verneed):
				printf("%15s", "GNU_VERNEED");
				break;
			case(SHT_GNU_versym):
				printf("%15s", "GNU_VERSYM");
				break;
			default:
				printf("%15s", "unknown");
				break;
		}

		printf(" | ");
		if (sec_headers[i].sh_flags & SHF_WRITE)
			printf("W");
		if (sec_headers[i].sh_flags & SHF_ALLOC)
			printf("A");
		if (sec_headers[i].sh_flags & SHF_EXECINSTR)
			printf("X");
		if (sec_headers[i].sh_flags & SHF_MERGE)
			printf("M");
		if (sec_headers[i].sh_flags & SHF_STRINGS)
			printf("S");
		if (sec_headers[i].sh_flags & SHF_INFO_LINK)
			printf("I");
		if (sec_headers[i].sh_flags & SHF_LINK_ORDER)
			printf("L");
		if (sec_headers[i].sh_flags & SHF_OS_NONCONFORMING)
			printf("O");
		if (sec_headers[i].sh_flags & SHF_GROUP)
			printf("G");
		if (sec_headers[i].sh_flags & SHF_TLS)
			printf("T");
		if (sec_headers[i].sh_flags & SHF_COMPRESSED)
			printf("C");

		printf(" 	| ");
		printf("0x%08lx", sec_headers[i].sh_addr);

		printf(" | ");
		printf("%10lu", sec_headers[i].sh_offset);

		printf(" | ");
		printf("0x%08lx", sec_headers[i].sh_size);

		printf(" | ");
		printf("%5i", sec_headers[i].sh_link);

		printf(" | ");
		printf("%5i", sec_headers[i].sh_info);

		printf(" | ");
		printf("%5lu", sec_headers[i].sh_addralign);

		printf(" | ");
		printf("%08lx", sec_headers[i].sh_entsize);

		printf("\n");
	}
}
