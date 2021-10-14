/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:13:07 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 11:40:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	parse_symbols_nm_x64(t_NmInfo64 *elf, t_SymHolder64 *holders,
							int sym_num)
{
	int	i;

	i = 0;
	while (++i < sym_num)
	{
		if (ELF64_ST_TYPE(elf->symbols[i].st_info) == STT_SECTION
			|| ELF64_ST_TYPE(elf->symbols[i].st_info) == STT_FILE)
			holders[i].skip = 1;
		else
			holders[i].skip = 0;
		holders[i].value = elf->symbols[i].st_value;
		holders[i].type = deduce_symbol_type_x64(&(elf->symbols[i]),
				elf->sec_headers, elf->sec_str_p);
		holders[i].name = elf->sym_str_p + elf->symbols[i].st_name;
	}
}

void	symbols_display_nm_x64(t_SymHolder64 *holders, int sym_num)
{
	int	i;

	i = 0;
	while (++i < sym_num)
	{
		if (holders[i].skip)
			continue ;
		if ((holders[i].value == 0 && (holders[i].type == 'd'
					|| holders[i].type == 'w' || holders[i].type == 'v'))
			|| holders[i].type == 'U')
			printf("%16s ", " ");
		else
			printf("%016lx ", holders[i].value);
		printf("%c ", holders[i].type);
		printf("%s\n", holders[i].name);
	}
}

void	print_symbols_nm_x64(t_NmInfo64 *elf)
{
	int					sym_num;
	t_SymHolder64		*holders;

	sym_num = (elf->symtab_header->sh_size / sizeof(Elf64_Sym));
	holders = malloc((sym_num) * sizeof(t_SymHolder64));
	if (!holders)
		exit(1);
	parse_symbols_nm_x64(elf, holders, sym_num);
	sort_symbols_x64(holders, sym_num);
	symbols_display_nm_x64(holders, sym_num);
	free(holders);
}
