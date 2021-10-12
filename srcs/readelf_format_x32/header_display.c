/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:02:25 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 11:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_elf_header_x32(Elf32_Ehdr *header)
{
	printf("	==== ELF FILE HEADER ====\n");

	/* Displaying magic bytes e_ident[EI_MAG] */
	printf("> Magic:				%02x %02x %02x %02x\n", header->e_ident[EI_MAG0], header->e_ident[EI_MAG1], header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
	
	/* Displaying file class e_ident[EI_CLASS] */
	printf("> Class:				");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid\n");
			break;
	}

	/* Displaying file data format e_ident[EI_DATA] */
	printf("> Data:					");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data format\n");
			break;
	}

	/* Displaying version e_ident[EI_VERSION] */
	printf("> Version:				");
	switch (header->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("Not found\n");
			break;
	}

	/* Displaying OS ABI informations e_ident[EI_OSABI] */
	printf("> OS/ABI:				");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("IBM-AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM AEABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) app\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	/* Displaying object file type e_type*/
	printf("> Type:					");
	switch(header->e_type)
	{
		case(ET_REL):
			printf("REL (relocatable)\n");
			break;
		case(ET_EXEC):
			printf("EXEC (executable)\n");
			break;
		case(ET_DYN):
			printf("DYN (shared)\n");
			break;
		case(ET_CORE):
			printf("CORE (core)\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	/* Displaying machine e_machine*/
	printf("> Machine:				");
	switch(header->e_machine)
	{
		case(EM_NONE):
			printf("None\n");
			break;
		case(EM_SPARC):
			printf("SPARC\n");
			break;
		case(EM_386):
			printf("Intel x86\n");
			break;
		case(EM_PPC64):
			printf("PowerPC 64\n");
			break;
		case(EM_ARM):
			printf("ARM\n");
			break;
		case(EM_x86_64):
			printf("Advanced Micro Devices X86-64\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	/* Displaying object file version e_version */
	printf("> Version				");
	switch(header->e_version)
	{
		case(EV_NONE):
			printf("0x0\n");
			break;
		case(EV_CURRENT):
			printf("0x1\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	/* Displaying program entry point e_entry */
	printf("> Entry point:				0x%08x\n", header->e_entry);

	/* Displaying Program header table offset in file e_phoff*/
	printf("> Segment header table offset:		%u\n", header->e_phoff);

	/* Displaying Section header table offset in file e_shoff */
	printf("> Section header table offset:		%u\n", header->e_shoff);

	/* ELF flags. NONE on Intel processors, some in ARM e_flags */
	printf("> Processor flags:			0x%i\n", header->e_flags);

	/* Displaying the current header size e_ehsize */
	printf("> Size of this header:			%i (bytes)\n", header->e_ehsize);

	/* Program Header table size in file e_phentsize */
	printf("> Segment header table size:		%i (bytes)\n", header->e_phentsize);

	/* Program Header table count e_phnum */
	printf("> Segment header table count:		%i\n", header->e_phnum);

	/* Section Header table size in file e_shentsize */
	printf("> Section header table size:		%i (bytes)\n", header->e_shentsize);

	/* Section Header table count e_shnum */
	printf("> Section header table count:		%i\n", header->e_shnum);

	/* Section Header string table index in Section Header section e_shstrndx */
	printf("> Section header string table:		%i\n", header->e_shstrndx);
}
