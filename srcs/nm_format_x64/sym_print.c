/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:13:07 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 11:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_symbols_nm_x64(Elf64_Shdr *sec_symtab_header, Elf64_Sym *symbols, const char *sec_sym_strtab_pointer, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer)
{
	int sym_num = (sec_symtab_header->sh_size / sizeof(Elf64_Sym));
	SymHolder64	*holders = malloc((sym_num) * sizeof(SymHolder64));

	for (int i = 1; i < sym_num; i++)
	{
		if (ELF64_ST_TYPE(symbols[i].st_info) == STT_SECTION || ELF64_ST_TYPE(symbols[i].st_info) == STT_FILE)
			holders[i].skip = 1;
		else
			holders[i].skip = 0;
		holders[i].value = symbols[i].st_value;
		holders[i].type = deduce_symbol_type_x64(&symbols[i], sec_headers, sec_strtab_pointer);
		holders[i].name = sec_sym_strtab_pointer + symbols[i].st_name;
	}

	sort_symbols_x64(holders, sym_num);

	for (int i = 1; i < sym_num; i++)
	{
		if (holders[i].skip)
			continue;
		if ((holders[i].value == 0 && (holders[i].type == 'd' || holders[i].type == 'w' || holders[i].type == 'v')) || holders[i].type == 'U')
			printf("%16s ", " ");
		else
			printf("%016lx ", holders[i].value);
		printf("%c ", holders[i].type);
		printf("%s\n", holders[i].name);
	}
	free(holders);
}
