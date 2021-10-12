/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:11 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 11:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_symbols_nm_x32(Elf32_Shdr *sec_symtab_header, Elf32_Sym *symbols, const char *sec_sym_strtab_pointer, Elf32_Shdr *sec_headers, const char *sec_strtab_pointer)
{
	int sym_num = (sec_symtab_header->sh_size / sizeof(Elf32_Sym));
	SymHolder32	*holders = malloc((sym_num) * sizeof(SymHolder32));

	for (int i = 1; i < sym_num; i++)
	{
		if (ELF32_ST_TYPE(symbols[i].st_info) == STT_SECTION || ELF32_ST_TYPE(symbols[i].st_info) == STT_FILE)
			holders[i].skip = 1;
		else
			holders[i].skip = 0;
		holders[i].value = symbols[i].st_value;
		holders[i].type = deduce_symbol_type_x32(&symbols[i], sec_headers, sec_strtab_pointer);
		holders[i].name = sec_sym_strtab_pointer + symbols[i].st_name;
	}

	sort_symbols_x32(holders, sym_num);

	for (int i = 1; i < sym_num; i++)
	{
		if (holders[i].skip)
			continue;
		if ((holders[i].value == 0 && (holders[i].type == 'd' || holders[i].type == 'w' || holders[i].type == 'v')) || holders[i].type == 'U')
			printf("%8s ", " ");
		else
			printf("%08x ", holders[i].value);
		
		printf("%c ", holders[i].type);
		printf("%s\n", holders[i].name);
	}
	free(holders);
}
