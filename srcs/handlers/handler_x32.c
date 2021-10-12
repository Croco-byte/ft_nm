/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:15:57 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 15:29:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

Elf32_Shdr	*symtab_h_x32(Elf32_Ehdr *header, Elf32_Shdr *sec_h, char *fname)
{
	int	i;

	i = -1;
	while (++i < header->e_shnum)
	{
		if (sec_headers[i].sh_type == SHT_SYMTAB)
			return (&sec_headers[i]);
	}
	printf("nm: %s: no symbols\n", filename);
	return (0);
}



void	handle_elf32(void *p, char *filename, int readelf)
{
	Elf32_Ehdr	*header;
	Elf32_Phdr	*seg_hs;
	Elf32_Shdr	*sec_hs;
	Elf32_Shdr	*sec_str_h;
	const char	*sec_strtab_pointer;
	Elf32_Shdr	*sec_symtab_header;
	Elf32_Sym	*symbols;
	Elf32_Shdr	*sym_str_h;
	const char	*sym_str_p;

	header = (Elf32_Ehdr *)p;
	seg_hs = (Elf32_Phdr *)(p + header->e_phoff);
	sec_hs = (Elf32_Shdr *)(p + header->e_shoff);
	sec_str_h = &sec_hs[header->e_shstrndx];
	sec_str_p = p + sec_str_h->sh_offset;
	sec_sym_h = symtab_h_x32(header, sec_hs, filename);
	if (!sec_sym_h)
		return ;
	symbols = p + sec_sym_h->sh_offset;
	sym_str_h = &sec_hs[sec_sym_h->sh_link];
	sym_str_p = p + (sym_str_h->sh_offset);

}

/*

	Elf32_Ehdr	*header						= (Elf32_Ehdr *)p;
	Elf32_Phdr	*seg_headers				= (Elf32_Phdr *)(p + header->e_phoff);
	Elf32_Shdr	*sec_headers				= (Elf32_Shdr *)(p + header->e_shoff);
	Elf32_Shdr	*sec_strtab_header			= &sec_headers[header->e_shstrndx];
	const char	*sec_strtab_pointer			= p + sec_strtab_header->sh_offset;
	Elf32_Shdr	*sec_symtab_header			= symtab_h_x32(header, sec_headers, filename);
	if (!sec_symtab_header)
		return ;
	Elf32_Sym	*symbols					= p + sec_symtab_header->sh_offset;
	Elf32_Shdr	*sec_sym_strtab_header		= &sec_headers[sec_symtab_header->sh_link];
	const char	*sec_sym_strtab_pointer		= p + (sec_sym_strtab_header->sh_offset);

	if (readelf)
	{
		print_elf_header_x32(header);
		print_program_headers_x32(header, seg_headers);
		print_section_headers_x32(header, sec_headers, sec_strtab_pointer);
		print_symbols_readelf_x32(sec_symtab_header, symbols, sec_sym_strtab_pointer);
	}
	else
		print_symbols_nm_x32(sec_symtab_header, symbols, sec_sym_strtab_pointer, sec_headers, sec_strtab_pointer);


*/
