/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 11:25:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_readelf_x32(t_NmInfo32 *elf)
{
	readelf_header_x32(elf->header);
	readelf_progheaders_x32(elf->header, elf->seg_headers);
	readelf_secheaders_x32(elf->header, elf->sec_headers, elf->sec_str_p);
	readelf_symbols_x32(elf->symtab_header, elf->symbols, elf->sym_str_p);
}
