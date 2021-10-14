/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:56 by user42            #+#    #+#             */
/*   Updated: 2021/10/13 18:16:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	symbols_part_1_x32(Elf32_Sym *symbols, int i)
{
	printf("> %4i | ", i);
	printf("%08x | ", symbols[i].st_value);
	printf("%5u | ", symbols[i].st_size);
	if (ELF32_ST_TYPE(symbols[i].st_info) == STT_NOTYPE)
		printf("%10s", "NOTYPE");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_OBJECT)
		printf("%10s", "OBJECT");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FUNC)
		printf("%10s", "FUNC");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_SECTION)
		printf("%10s", "SECTION");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FILE)
		printf("%10s", "FILE");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_COMMON)
		printf("%10s", "COMMON");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_TLS)
		printf("%10s", "TLS");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_NUM)
		printf("%10s", "NUM");
	else if (ELF32_ST_TYPE(symbols[i].st_info) == STT_GNU_IFUNC)
		printf("%10s", "GNU_IFUNC");
	else
		printf("%10s", "?");
}

void	symbols_part_2_x32(Elf32_Sym *symbols, int i)
{
	if (ELF32_ST_BIND(symbols[i].st_info) == STB_LOCAL)
		printf("%11s", "LOCAL");
	else if (ELF32_ST_BIND(symbols[i].st_info) == STB_GLOBAL)
		printf("%11s", "GLOBAL");
	else if (ELF32_ST_BIND(symbols[i].st_info) == STB_WEAK)
		printf("%11s", "WEAK");
	else if (ELF32_ST_BIND(symbols[i].st_info) == STB_NUM)
		printf("%11s", "NUM");
	else if (ELF32_ST_BIND(symbols[i].st_info) == STB_GNU_UNIQUE)
		printf("%11s", "GNU_UNIQUE");
	else
		printf("%11s", "?");
	printf(" | ");
	if (ELF32_ST_VISIBILITY(symbols[i].st_other) == STV_DEFAULT)
		printf("%10s", "DEFAULT");
	else if (ELF32_ST_VISIBILITY(symbols[i].st_other) == STV_INTERNAL)
		printf("%10s", "INTERNAL");
	else if (ELF32_ST_VISIBILITY(symbols[i].st_other) == STV_HIDDEN)
		printf("%10s", "HIDDEN");
	else if (ELF32_ST_VISIBILITY(symbols[i].st_other) == STV_PROTECTED)
		printf("%10s", "PROTECTED");
	else
		printf("%10s", "?");
}

void	readelf_symbols_x32(Elf32_Shdr *sec_symtab_header, Elf32_Sym *symbols,
							const char *sec_sym_strtab_pointer)
{
	int		i;
	int		sym_num;

	i = -1;
	printf("\n\n	==== SYMBOL TABLE (READELF STYLE) ====\n");
	sym_num = (sec_symtab_header->sh_size / sizeof(Elf32_Sym));
	while (++i < sym_num)
	{
		symbols_part_1_x32(symbols, i);
		printf(" | ");
		symbols_part_2_x32(symbols, i);
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
