/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:14:34 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 14:15:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

Elf64_Shdr	*find_symtab_header_x64(Elf64_Ehdr *header, Elf64_Shdr *sec_headers, char *filename)
{
	for (int i = 0; i < header->e_shnum; i++)
	{
		if (sec_headers[i].sh_type == SHT_SYMTAB)
			return &sec_headers[i];
	}
	printf("nm: %s: no symbols\n", filename);
	return (0);
}

void		handle_elf64(void *p, char *filename, int readelf)
{
	Elf64_Ehdr	*header						= (Elf64_Ehdr *)p;
	Elf64_Phdr	*seg_headers				= (Elf64_Phdr *)(p + header->e_phoff);
	Elf64_Shdr	*sec_headers				= (Elf64_Shdr *)(p + header->e_shoff);
	Elf64_Shdr	*sec_strtab_header			= &sec_headers[header->e_shstrndx];
	const char	*sec_strtab_pointer			= p + sec_strtab_header->sh_offset;
	Elf64_Shdr	*sec_symtab_header			= find_symtab_header_x64(header, sec_headers, filename);
	if (!sec_symtab_header)
		return ;
	Elf64_Sym	*symbols					= p + sec_symtab_header->sh_offset;
	Elf64_Shdr	*sec_sym_strtab_header		= &sec_headers[sec_symtab_header->sh_link];
	const char	*sec_sym_strtab_pointer		= p + (sec_sym_strtab_header->sh_offset);
	
	if (readelf)
	{
		print_elf_header_x64(header);
		print_program_headers_x64(header, seg_headers);
		print_section_headers_x64(header, sec_headers, sec_strtab_pointer);
		print_symbols_readelf_x64(sec_symtab_header, symbols, sec_sym_strtab_pointer);
	}
	else
		print_symbols_nm_x64(sec_symtab_header, symbols, sec_sym_strtab_pointer, sec_headers, sec_strtab_pointer);
}
