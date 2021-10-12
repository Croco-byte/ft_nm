/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:11:45 by user42            #+#    #+#             */
/*   Updated: 2021/10/11 17:12:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	deduce_symbol_type_x64(Elf64_Sym *sym, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer)
{
	int	bind = ELF64_ST_BIND(sym->st_info);
	int type = ELF64_ST_TYPE(sym->st_info);

	if (bind == STB_GNU_UNIQUE)
		return 'u';
	if (bind == STB_WEAK && type == STT_OBJECT && sym->st_shndx == 0)
		return 'v';
	if (bind == STB_WEAK && type == STT_OBJECT && sym->st_shndx != 0)
		return 'V';
	if (bind == STB_WEAK && sym->st_shndx == 0)
		return 'w';
	if (bind == STB_WEAK && sym->st_shndx != 0)
		return 'W';

	if (type == STT_GNU_IFUNC)
		return 'i';

	if (sym->st_shndx == 0xfff1)
		return 'A';
	if (sym->st_shndx == 0xfff2)
		return 'C';
	if (sym->st_shndx == 0)
		return 'U';

	char *uninit_data_secs[]	= {".bss", ".tbss"};
	char *init_data_secs[]		= {".data", ".dynamic", ".got", ".tdata", ".preinit"};
	char *ro_data_secs[]		= {".rodata", ".eh_frame", ".gcc_except_table"};
	char *code_secs[]			= {".text", ".init", ".fini"};
	char *debug_secs[]			= {".debug"};

	for (size_t i = 0; i < sizeof(uninit_data_secs) / sizeof(uninit_data_secs[0]); i++)
	{
		if (ft_strncmp(sec_strtab_pointer + (sec_headers[sym->st_shndx].sh_name), uninit_data_secs[i], ft_strlen(uninit_data_secs[i])) == 0)
			return bind == STB_GLOBAL ? 'B' : 'b';
	}
	for (size_t i = 0; i < sizeof(init_data_secs) / sizeof(init_data_secs[0]); i++)
	{
		if (ft_strncmp(sec_strtab_pointer + (sec_headers[sym->st_shndx].sh_name), init_data_secs[i], ft_strlen(init_data_secs[i])) == 0)
			return bind == STB_GLOBAL ? 'D' : 'd';
	}
	for (size_t i = 0; i < sizeof(ro_data_secs) / sizeof(ro_data_secs[0]); i++)
	{
		if (ft_strncmp(sec_strtab_pointer + (sec_headers[sym->st_shndx].sh_name), ro_data_secs[i], ft_strlen(ro_data_secs[i])) == 0)
			return bind == STB_GLOBAL ? 'R' : 'r';
	}
	for (size_t i = 0; i < sizeof(code_secs) / sizeof(code_secs[0]); i++)
	{
		if (ft_strncmp(sec_strtab_pointer + (sec_headers[sym->st_shndx].sh_name), code_secs[i], ft_strlen(code_secs[i])) == 0)
			return bind == STB_GLOBAL ? 'T' : 't';
	}
	for (size_t i = 0; i < sizeof(debug_secs) / sizeof(debug_secs[0]); i++)
	{
		if (ft_strncmp(sec_strtab_pointer + (sec_headers[sym->st_shndx].sh_name), debug_secs[i], ft_strlen(debug_secs[i])) == 0)
			return 'N';
	}

	return '?';
}
