/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:15:57 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 11:38:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

Elf32_Shdr	*symtab_h_x32(Elf32_Ehdr *header, Elf32_Shdr *sec_h, char *fname)
{
	int	i;

	i = -1;
	while (++i < header->e_shnum)
	{
		if (sec_h[i].sh_type == SHT_SYMTAB)
			return (&sec_h[i]);
	}
	printf("nm: %s: no symbols\n", fname);
	return (0);
}

int	parse_elf_x32(void *p, t_NmInfo32 *elf, char *f)
{
	elf->header = (Elf32_Ehdr *)p;
	elf->seg_headers = (Elf32_Phdr *)(p + elf->header->e_phoff);
	elf->sec_headers = (Elf32_Shdr *)(p + elf->header->e_shoff);
	elf->sec_str_h = &(elf->sec_headers[elf->header->e_shstrndx]);
	elf->sec_str_p = p + elf->sec_str_h->sh_offset;
	elf->symtab_header = symtab_h_x32(elf->header, elf->sec_headers, f);
	if (!elf->symtab_header)
		return (0);
	elf->symbols = p + elf->symtab_header->sh_offset;
	elf->sym_str_h = &(elf->sec_headers[elf->symtab_header->sh_link]);
	elf->sym_str_p = p + (elf->sym_str_h->sh_offset);
	return (1);
}

void	handle_elf32(void *p, char *filename, int readelf)
{
	t_NmInfo32	*parsed_elf;

	parsed_elf = malloc(1 * sizeof(t_NmInfo32));
	if (!parsed_elf)
		exit(1);
	if (!parse_elf_x32(p, parsed_elf, filename))
	{
		free(parsed_elf);
		return ;
	}
	if (readelf)
		print_readelf_x32(parsed_elf);
	else
		print_symbols_nm_x32(parsed_elf);
	free(parsed_elf);
}
