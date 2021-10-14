/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:02:25 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 10:59:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	header_part_1_x32(Elf32_Ehdr *header)
{
	printf("	==== ELF FILE HEADER ====\n");
	printf("> Magic:				%02x %02x %02x %02x\n",
		header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
		header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
	printf("> Class:				");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid\n");
	printf("> Data:					");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data format\n");
	printf("> Version:				");
	if (header->e_ident[EI_VERSION] == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("Not found\n");
}

void	header_part_2_x32(Elf32_Ehdr *header)
{
	printf("> OS/ABI:				");
	if (header->e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX System V\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("HP-UX\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("NetBSD\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("Linux\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("Solaris\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("FreeBSD\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("TRU64\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD)
		printf("OpenBSD\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI)
		printf("ARM ARABI\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone (embedded) app\n");
	else
		printf("Unknown\n");
}

void	header_part_3_x32(Elf32_Ehdr *header)
{
	printf("> Type:					");
	if (header->e_type == ET_REL)
		printf("REL (relocatable)\n");
	else if (header->e_type == ET_EXEC)
		printf("EXEC (executable)\n");
	else if (header->e_type == ET_DYN)
		printf("DYN (shared)\n");
	else if (header->e_type == ET_CORE)
		printf("CORE (core)\n");
	else
		printf("Unknown\n");
	printf("> Machine:				");
	print_machine(header->e_machine);
	printf("\n> Version:				");
	if (header->e_version == EV_NONE)
		printf("0x0\n");
	else if (header->e_version == EV_CURRENT)
		printf("0x1\n");
	else
		printf("Unknown\n");
}

void	readelf_header_x32(Elf32_Ehdr *header)
{
	printf("	==== ELF FILE HEADER ====\n");
	header_part_1_x32(header);
	header_part_2_x32(header);
	header_part_3_x32(header);
	printf("> Entry point:				0x%08x\n", header->e_entry);
	printf("> Segment header table offset:		%u\n", header->e_phoff);
	printf("> Section header table offset:		%u\n", header->e_shoff);
	printf("> Processor flags:			0x%i\n", header->e_flags);
	printf("> Size of this header:			%i (bytes)\n", header->e_ehsize);
	printf("> Segment header table size:		%i (bytes)\n",
		header->e_phentsize);
	printf("> Segment header table count:		%i\n", header->e_phnum);
	printf("> Section header table size:		%i (bytes)\n",
		header->e_shentsize);
	printf("> Section header table count:		%i\n", header->e_shnum);
	printf("> Section header string table:		%i\n", header->e_shstrndx);
}
