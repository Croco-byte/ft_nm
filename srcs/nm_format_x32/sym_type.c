/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:14:07 by user42            #+#    #+#             */
/*   Updated: 2021/10/13 16:41:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	special_typesx32(Elf32_Sym *sym, int bind, int type)
{
	if (bind == STB_GNU_UNIQUE)
		return ('u');
	if (bind == STB_WEAK && type == STT_OBJECT && sym->st_shndx == 0)
		return ('v');
	if (bind == STB_WEAK && type == STT_OBJECT && sym->st_shndx != 0)
		return ('V');
	if (bind == STB_WEAK && sym->st_shndx == 0)
		return ('w');
	if (bind == STB_WEAK && sym->st_shndx != 0)
		return ('W');
	if (type == STT_GNU_IFUNC)
		return ('i');
	if (sym->st_shndx == 0xfff1)
		return ('A');
	if (sym->st_shndx == 0xfff2)
		return ('C');
	if (sym->st_shndx == 0)
		return ('U');
	return (0);
}

int	section_types_1x32(Elf32_Shdr *sec_headers, const char *sec_strtab_pointer,
		Elf32_Sym *sym, int bind)
{
	if (is_uninit_x32(sec_headers, sec_strtab_pointer, sym))
	{
		if (bind == STB_GLOBAL)
			return ('B');
		return ('b');
	}
	else if (is_init_x32(sec_headers, sec_strtab_pointer, sym))
	{
		if (bind == STB_GLOBAL)
			return ('D');
		return ('d');
	}
	else if (is_ro_x32(sec_headers, sec_strtab_pointer, sym))
	{
		if (bind == STB_GLOBAL)
			return ('R');
		return ('r');
	}
	return (0);
}

int	section_types_2x32(Elf32_Shdr *sec_headers, const char *sec_strtab_pointer,
		Elf32_Sym *sym, int bind)
{
	if (is_code_x32(sec_headers, sec_strtab_pointer, sym))
	{
		if (bind == STB_GLOBAL)
			return ('T');
		return ('t');
	}
	else if (is_debug_x32(sec_headers, sec_strtab_pointer, sym))
	{
		if (bind == STB_GLOBAL)
			return ('N');
		return ('n');
	}
	return (0);
}

char	deduce_symbol_type_x32(Elf32_Sym *sym,
		Elf32_Shdr *sec_headers, const char *sec_strtab_pointer)
{
	int	bind;
	int	type;
	int	spec;
	int	sec_types;

	bind = ELF32_ST_BIND(sym->st_info);
	type = ELF32_ST_TYPE(sym->st_info);
	spec = special_typesx32(sym, bind, type);
	if (spec != 0)
		return (spec);
	sec_types = section_types_1x32(sec_headers, sec_strtab_pointer, sym, bind);
	if (sec_types != 0)
		return (sec_types);
	sec_types = section_types_2x32(sec_headers, sec_strtab_pointer, sym, bind);
	if (sec_types != 0)
		return (sec_types);
	return ('?');
}
