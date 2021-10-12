/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:42:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 15:08:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM
# define FT_NM

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"
#include "elf.h"

typedef struct
{
	int				skip;
	Elf64_Addr		value;
	char			type;
	const char *	name;
}					SymHolder64;

typedef struct
{
	int				skip;
	Elf32_Addr		value;
	char			type;
	const char *	name;
}					SymHolder32;

/* Handler ; FATELF */
void		handle_fatelf(void *p, int readelf);

/* Handler ; x32 */
void		handle_elf32(void *p, char *filename, int readelf);

/* Handler ; x64 */
void		handle_elf64(void *p, char *filename, int readelf);

/* Readelf format ; x32 */
void		print_elf_header_x32(Elf32_Ehdr *header);
void		print_section_headers_x32(Elf32_Ehdr *header, Elf32_Shdr *sec_headers, const char *sec_strtab_pointer);
void		print_program_headers_x32(Elf32_Ehdr *header, Elf32_Phdr *seg_headers);
void		print_symbols_readelf_x32(Elf32_Shdr *sec_symtab_header, Elf32_Sym *symbols, const char *sec_sym_strtab_pointer);

/* Readelf format ; x64 */
void		print_elf_header_x64(Elf64_Ehdr *header);
void		print_section_headers_x64(Elf64_Ehdr *header, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer);
void		print_program_headers_x64(Elf64_Ehdr *header, Elf64_Phdr *seg_headers);
void		print_symbols_readelf_x64(Elf64_Shdr *sec_symtab_header, Elf64_Sym *symbols, const char *sec_sym_strtab_pointer);

/* Nm format ; x32 */
void		print_symbols_nm_x32(Elf32_Shdr *sec_symtab_header, Elf32_Sym *symbols, const char *sec_sym_strtab_pointer, Elf32_Shdr *sec_headers, const char *sec_strtab_pointer);
void		sort_symbols_x32(SymHolder32 *holders, int sym_num);
char		deduce_symbol_type_x32(Elf32_Sym *sym, Elf32_Shdr *sec_headers, const char *sec_strtab_pointer);

/* Nm format ; x64 */
void		print_symbols_nm_x64(Elf64_Shdr *sec_symtab_header, Elf64_Sym *symbols, const char *sec_sym_strtab_pointer, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer);
void		sort_symbols_x64(SymHolder64 *holders, int sym_num);
char		deduce_symbol_type_x64(Elf64_Sym *sym, Elf64_Shdr *sec_headers, const char *sec_strtab_pointer);

/* Utilities */
void		print_machine(uint16_t flag);
void		print_class(uint8_t flag);



#endif
