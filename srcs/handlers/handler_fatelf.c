/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_fatelf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:26:51 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 15:12:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	handle_fatelf(void *p, int readelf)
{
	int				i;
	FATELF_header	*fatelf_header;
	FATELF_record	record;

	i = -1;
	fatelf_header = (FATELF_header *)p;
	printf("FATELF file including %i binaries", fatelf_header->num_records);
	while (++i < fatelf_header->num_records)
	{
		record = fatelf_header->records[i];
		printf("\n[Binary n°%i | Arch : ", i + 1);
		print_machine(fatelf_header->records[i].machine);
		printf(" | ");
		print_class(fatelf_header->records[i].word_size);
		printf(" | Offset in file : 0x%08lx]\n", record.offset);
		if (record.word_size == 1)
			handle_elf32(p + record.offset, " ", readelf);
		else if (record.word_size == 2)
			handle_elf64(p + record.offset, " ", readelf);
	}
}
