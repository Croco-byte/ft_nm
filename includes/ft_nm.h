/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:42:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 12:11:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include "elf.h"

typedef struct s_SymHolder64
{
	int				skip;
	Elf64_Addr		value;
	char			type;
	const char		*name;
}					t_SymHolder64;

typedef struct s_SymHolder32
{
	int				skip;
	Elf32_Addr		value;
	char			type;
	const char		*name;
}					t_SymHolder32;

typedef struct s_NmInfo32
{
	Elf32_Ehdr	*header;
	Elf32_Phdr	*seg_headers;
	Elf32_Shdr	*sec_headers;
	Elf32_Shdr	*sec_str_h;
	const char	*sec_str_p;
	Elf32_Shdr	*symtab_header;
	Elf32_Sym	*symbols;
	Elf32_Shdr	*sym_str_h;
	const char	*sym_str_p;
}				t_NmInfo32;

typedef struct s_NmInfo64
{
	Elf64_Ehdr	*header;
	Elf64_Phdr	*seg_headers;
	Elf64_Shdr	*sec_headers;
	Elf64_Shdr	*sec_str_h;
	const char	*sec_str_p;
	Elf64_Shdr	*symtab_header;
	Elf64_Sym	*symbols;
	Elf64_Shdr	*sym_str_h;
	const char	*sym_str_p;
}				t_NmInfo64;

/* Handler ; FATELF */
void		handle_fatelf(void *p, int readelf);

/* Handler ; x32 */
void		handle_elf32(void *p, char *filename, int readelf);

/* Handler ; x64 */
void		handle_elf64(void *p, char *filename, int readelf);

/* Readelf format ; x32 */
void		print_readelf_x32(t_NmInfo32 *elf);
void		readelf_header_x32(Elf32_Ehdr *header);
void		readelf_secheaders_x32(Elf32_Ehdr *header, Elf32_Shdr *sec_headers,
				const char *sec_strtab_pointer);
void		readelf_progheaders_x32(Elf32_Ehdr *header,
				Elf32_Phdr *seg_headers);
void		readelf_symbols_x32(Elf32_Shdr *sec_symtab_header,
				Elf32_Sym *symbols, const char *sec_sym_strtab_pointer);

/* Readelf format ; x64 */
void		print_readelf_x64(t_NmInfo64 *elf);
void		readelf_header_x64(Elf64_Ehdr *header);
void		readelf_secheaders_x64(Elf64_Ehdr *header, Elf64_Shdr *sec_headers,
				const char *sec_strtab_pointer);
void		readelf_progheaders_x64(Elf64_Ehdr *header,
				Elf64_Phdr *seg_headers);
void		readelf_symbols_x64(Elf64_Shdr *sec_symtab_header,
				Elf64_Sym *symbols, const char *sec_sym_strtab_pointer);

/* Nm format ; x32 */
void		print_symbols_nm_x32(t_NmInfo32 *elf);
void		sort_symbols_x32(t_SymHolder32 *holders, int sym_num);
char		deduce_symbol_type_x32(Elf32_Sym *sym, Elf32_Shdr *sec_headers,
				const char *sec_strtab_pointer);
int			is_uninit_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
				Elf32_Sym *sym);
int			is_init_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
				Elf32_Sym *sym);
int			is_ro_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
				Elf32_Sym *sym);
int			is_code_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
				Elf32_Sym *sym);
int			is_debug_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
				Elf32_Sym *sym);

/* Nm format ; x64 */
void		print_symbols_nm_x64(t_NmInfo64 *elf);
void		sort_symbols_x64(t_SymHolder64 *holders, int sym_num);
char		deduce_symbol_type_x64(Elf64_Sym *sym, Elf64_Shdr *sec_headers,
				const char *sec_strtab_pointer);
int			is_uninit_x64(Elf64_Shdr *sec_headers, const char *sec_strtab_p,
				Elf64_Sym *sym);
int			is_init_x64(Elf64_Shdr *sec_headers, const char *sec_strtab_p,
				Elf64_Sym *sym);
int			is_ro_x64(Elf64_Shdr *sec_headers, const char *sec_strtab_p,
				Elf64_Sym *sym);
int			is_code_x64(Elf64_Shdr *sec_headers, const char *sec_strtab_p,
				Elf64_Sym *sym);
int			is_debug_x64(Elf64_Shdr *sec_headers, const char *sec_strtab_p,
				Elf64_Sym *sym);

/* Utilities */
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			which_elf(unsigned char class);
void		print_machine(uint16_t flag);

#endif
