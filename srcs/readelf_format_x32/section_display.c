/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:20 by user42            #+#    #+#             */
/*   Updated: 2021/10/13 17:55:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	section_part_1_x32(Elf32_Shdr *sec_headers,
			const char *sec_strtab_pointer, int i)
{
	printf("> %3i | ", i);
	printf("%18s | ", (sec_strtab_pointer + sec_headers[i].sh_name));
	if (sec_headers[i].sh_type == SHT_NULL)
		printf("%15s", "NULL");
	else if (sec_headers[i].sh_type == SHT_PROGBITS)
		printf("%15s", "PROGBITS");
	else if (sec_headers[i].sh_type == SHT_SYMTAB)
		printf("%15s", "SYMTAB");
	else if (sec_headers[i].sh_type == SHT_STRTAB)
		printf("%15s", "STRTAB");
	else if (sec_headers[i].sh_type == SHT_RELA)
		printf("%15s", "RELA");
	else if (sec_headers[i].sh_type == SHT_HASH)
		printf("%15s", "HASH");
	else if (sec_headers[i].sh_type == SHT_DYNAMIC)
		printf("%15s", "DYNAMIC");
	else if (sec_headers[i].sh_type == SHT_NOTE)
		printf("%15s", "NOTE");
	else if (sec_headers[i].sh_type == SHT_NOBITS)
		printf("%15s", "NOBITS");
	else if (sec_headers[i].sh_type == SHT_REL)
		printf("%15s", "REL");
	else if (sec_headers[i].sh_type == SHT_SHLIB)
		printf("%15s", "SHLIB");
}

void	section_part_2_x32(Elf32_Shdr *sec_headers, int i)
{
	if (sec_headers[i].sh_type == SHT_DYNSYM)
		printf("%15s", "DYNSYM");
	else if (sec_headers[i].sh_type == SHT_INIT_ARRAY)
		printf("%15s", "INIT_ARRAY");
	else if (sec_headers[i].sh_type == SHT_FINI_ARRAY)
		printf("%15s", "FINI_ARRAY");
	else if (sec_headers[i].sh_type == SHT_PREINIT_ARRAY)
		printf("%15s", "PREINIT_ARRAY");
	else if (sec_headers[i].sh_type == SHT_GROUP)
		printf("%15s", "GROUP");
	else if (sec_headers[i].sh_type == SHT_SYMTAB_SHNDX)
		printf("%15s", "SYMTAB_SHNDX");
	else if (sec_headers[i].sh_type == SHT_NUM)
		printf("%15s", "NUM");
	else if (sec_headers[i].sh_type == SHT_LOOS)
		printf("%15s", "LOOS");
	else if (sec_headers[i].sh_type == SHT_GNU_ATTRIBUTES)
		printf("%15s", "GNU_ATTRIBUTES");
	else if (sec_headers[i].sh_type == SHT_GNU_HASH)
		printf("%15s", "GNU_HASH");
	else if (sec_headers[i].sh_type == SHT_GNU_LIBLIST)
		printf("%15s", "GNU_LIBLIST");
	else if (sec_headers[i].sh_type == SHT_GNU_verdef)
		printf("%15s", "GNU_VERDEF");
}

void	section_part_3_x32(Elf32_Shdr *sec_headers, int i)
{
	if (sec_headers[i].sh_type == SHT_GNU_verneed)
		printf("%15s", "GNU_VERNEED");
	else if (sec_headers[i].sh_type == SHT_GNU_versym)
		printf("%15s", "GNU_VERSYM");
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
}

void	section_part_4_x32(Elf32_Shdr *sec_headers, int i)
{
	if (sec_headers[i].sh_flags & SHF_TLS)
		printf("T");
	if (sec_headers[i].sh_flags & SHF_COMPRESSED)
		printf("C");
	printf(" 	| ");
	printf("0x%08x", sec_headers[i].sh_addr);
	printf(" | ");
	printf("%10x", sec_headers[i].sh_offset);
	printf(" | ");
	printf("0x%08x", sec_headers[i].sh_size);
	printf(" | ");
	printf("%5i", sec_headers[i].sh_link);
	printf(" | ");
	printf("%5i", sec_headers[i].sh_info);
	printf(" | ");
	printf("%5u", sec_headers[i].sh_addralign);
	printf(" | ");
	printf("%08x", sec_headers[i].sh_entsize);
}

void	readelf_secheaders_x32(Elf32_Ehdr *header, Elf32_Shdr *sec_headers,
			const char *sec_strtab_pointer)
{
	int		i;

	i = -1;
	printf("\n\n	==== SECTION HEADER TABLE ====\n");
	printf("(Index|Name|Type|Flags|Addr|Offset|Size|Links");
	printf("|Info|Alignment|Entry Size)\n\n");
	while (++i < header->e_shnum)
	{
		section_part_1_x32(sec_headers, sec_strtab_pointer, i);
		section_part_2_x32(sec_headers, i);
		section_part_3_x32(sec_headers, i);
		section_part_4_x32(sec_headers, i);
		printf("\n");
	}
}
