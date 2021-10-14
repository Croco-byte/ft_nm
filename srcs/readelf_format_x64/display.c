/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:54:34 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 11:26:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_readelf_x64(t_NmInfo64 *elf)
{
	readelf_header_x64(elf->header);
	readelf_progheaders_x64(elf->header, elf->seg_headers);
	readelf_secheaders_x64(elf->header, elf->sec_headers, elf->sec_str_p);
	readelf_symbols_x64(elf->symtab_header, elf->symbols, elf->sym_str_p);
}
