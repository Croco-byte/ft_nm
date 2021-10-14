/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:30:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 11:41:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	is_uninit_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
		Elf32_Sym *sym)
{
	size_t		i;
	char		**uninit_data_secs;

	uninit_data_secs = malloc(2 * sizeof(char *));
	if (!uninit_data_secs)
		exit(1);
	uninit_data_secs[0] = ".bss";
	uninit_data_secs[1] = ".tbss";
	i = -1;
	while (++i < 2)
	{
		if (ft_strncmp(sec_strtab_p + (sec_headers[sym->st_shndx].sh_name),
				uninit_data_secs[i], ft_strlen(uninit_data_secs[i])) == 0)
		{
			free(uninit_data_secs);
			return (1);
		}
	}
	free(uninit_data_secs);
	return (0);
}

int	is_init_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
		Elf32_Sym *sym)
{
	size_t		i;
	char		**init_data_secs;

	init_data_secs = malloc(6 * sizeof(char *));
	if (!init_data_secs)
		exit(1);
	init_data_secs[0] = ".data";
	init_data_secs[1] = ".tdata";
	init_data_secs[2] = ".dynamic";
	init_data_secs[3] = ".got";
	init_data_secs[4] = ".preinit";
	init_data_secs[5] = "__libc_subfreeres";
	i = -1;
	while (++i < 6)
	{
		if (ft_strncmp(sec_strtab_p + (sec_headers[sym->st_shndx].sh_name),
				init_data_secs[i], ft_strlen(init_data_secs[i])) == 0)
		{
			free(init_data_secs);
			return (1);
		}
	}
	free(init_data_secs);
	return (0);
}

int	is_ro_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
		Elf32_Sym *sym)
{
	size_t		i;
	char		**ro_data_secs;

	ro_data_secs = malloc(4 * sizeof(char *));
	if (!ro_data_secs)
		exit(1);
	ro_data_secs[0] = ".rodata";
	ro_data_secs[1] = ".eh_frame";
	ro_data_secs[2] = ".gcc_except_table";
	ro_data_secs[3] = ".interp";
	i = -1;
	while (++i < 4)
	{
		if (ft_strncmp(sec_strtab_p + (sec_headers[sym->st_shndx].sh_name),
				ro_data_secs[i], ft_strlen(ro_data_secs[i])) == 0)
		{
			free(ro_data_secs);
			return (1);
		}
	}
	free(ro_data_secs);
	return (0);
}

int	is_code_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
		Elf32_Sym *sym)
{
	size_t		i;
	char		**code_secs;

	code_secs = malloc(4 * sizeof(char *));
	if (!code_secs)
		exit(1);
	code_secs[0] = ".text";
	code_secs[1] = ".init";
	code_secs[2] = ".fini";
	code_secs[3] = "__libc_freeres_fn";
	i = -1;
	while (++i < 4)
	{
		if (ft_strncmp(sec_strtab_p + (sec_headers[sym->st_shndx].sh_name),
				code_secs[i], ft_strlen(code_secs[i])) == 0)
		{
			free(code_secs);
			return (1);
		}
	}
	free(code_secs);
	return (0);
}

int	is_debug_x32(Elf32_Shdr *sec_headers, const char *sec_strtab_p,
		Elf32_Sym *sym)
{
	size_t		i;
	char		**debug_secs;

	debug_secs = malloc(2 * sizeof(char *));
	if (!debug_secs)
		exit(1);
	debug_secs[0] = ".debug";
	debug_secs[1] = ".gnu.warning";
	i = -1;
	while (++i < 2)
	{
		if (ft_strncmp(sec_strtab_p + (sec_headers[sym->st_shndx].sh_name),
				debug_secs[i], ft_strlen(debug_secs[i])) == 0)
		{
			free(debug_secs);
			return (1);
		}
	}
	free(debug_secs);
	return (0);
}
