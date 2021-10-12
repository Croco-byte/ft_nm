/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:56 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 11:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_symbols_readelf_x32(Elf32_Shdr *sec_symtab_header, Elf32_Sym *symbols, const char *sec_sym_strtab_pointer)
{
	printf("\n\n	==== SYMBOL TABLE (READELF STYLE) ====\n");
	int sym_num = (sec_symtab_header->sh_size / sizeof(Elf32_Sym));
	for (int i = 0; i < sym_num; i++)
	{
		printf("> %4i | ", i);
		printf("%08x | ", symbols[i].st_value);
		printf("%5u | ", symbols[i].st_size);

		switch(ELF32_ST_TYPE(symbols[i].st_info))
		{
			case(STT_NOTYPE):
				printf("%10s", "NOTYPE");
				break;
			case(STT_OBJECT):
				printf("%10s", "OBJECT");
				break;
			case(STT_FUNC):
				printf("%10s", "FUNC");
				break;
			case(STT_SECTION):
				printf("%10s", "SECTION");
				break;
			case(STT_FILE):
				printf("%10s", "FILE");
				break;
			case(STT_COMMON):
				printf("%10s", "COMMON");
				break;
			case(STT_TLS):
				printf("%10s", "TLS");
				break;
			case(STT_NUM):
				printf("%10s", "NUM");
				break;
			case(STT_GNU_IFUNC):
				printf("%10s", "GNU_IFUNC");
				break;
			default:
				printf("%10s", "?");
				break;
		}

		printf(" | ");
		switch(ELF32_ST_BIND(symbols[i].st_info))
		{
			case(STB_LOCAL):
				printf("%11s", "LOCAL");
				break;
			case(STB_GLOBAL):
				printf("%11s", "GLOBAL");
				break;
			case(STB_WEAK):
				printf("%11s", "WEAK");
				break;
			case(STB_NUM):
				printf("%11s", "NUM");
				break;
			case(STB_GNU_UNIQUE):
				printf("%11s", "GNU_UNIQUE");
				break;
			default:
				printf("%10s", "?");
		}

		printf(" | ");
		switch(ELF32_ST_VISIBILITY(symbols[i].st_other))
		{
			case(STV_DEFAULT):
				printf("%10s", "DEFAULT");
				break;
			case(STV_INTERNAL):
				printf("%10s", "INTERNAL");
				break;
			case(STV_HIDDEN):
				printf("%10s", "HIDDEN");
				break;
			case(STV_PROTECTED):
				printf("%10s", "PROTECTED");
				break;
			default:
				printf("%10s", "?");
				break;
		}

		printf(" | ");
		if (symbols[i].st_shndx == 0xfff1)
			printf("ABS |");
		else if (symbols[i].st_shndx == 0xfff2)
			printf("COM |");
		else if (symbols[i].st_shndx == 0)
			printf("UND |");
		else
			printf("%3i | ", symbols[i].st_shndx);
		printf("%s", sec_sym_strtab_pointer + symbols[i].st_name);
		printf("\n");
	}
}
