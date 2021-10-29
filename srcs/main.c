/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:09 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 13:24:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	g_error_count = 0;

int	get_file_type(void *p)
{
	unsigned char	*magic;

	magic = (unsigned char *)p;
	if (*((uint32_t *)p) == 0x1F0E70FA)
		return (3);
	if (ft_strncmp((char *)magic, ELFMAG, 4) != 0)
		return (-1);
	return (which_elf(magic[EI_CLASS]));
}

void	file_error(char *filename, int err_type)
{
	g_error_count++;
	if (err_type == 0)
	{
		if (errno == ENOENT)
			printf("nm: '%s': No such file\n", filename);
	}
	else if (err_type == 1)
		printf("nm: '%s': Couldn't read ELF file informations\n", filename);
	else if (err_type == 2)
		printf("nm: %s: File format not recognized\n", filename);
}

void	small_files_errors(size_t st_size, char *filename)
{
	if (st_size <= 0)
		g_error_count++;
	else if (st_size < 4)
	{
		g_error_count++;
		printf("nm: %s: File truncated\n", filename);
	}
}

void	launch_nm(char *filename, int single_file, int readelf)
{
	struct stat		st;
	int				elf_fd;
	void			*p;
	int				type;

	elf_fd = open(filename, O_RDONLY);
	if (elf_fd < 0)
		return (file_error(filename, 0));
	if (!single_file)
		printf("\n%s:\n", filename);
	if (fstat(elf_fd, &st) != 0)
		return (file_error(filename, 1));
	if (st.st_size < 4)
		return (small_files_errors(st.st_size, filename));
	p = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, elf_fd, 0);
	type = get_file_type(p);
	if (type == -1)
		return (file_error(filename, 2));
	else if (type == 3)
		handle_fatelf(p, readelf);
	else if (type == 0)
		handle_elf32(p, filename, readelf);
	else
		handle_elf64(p, filename, readelf);
	close(elf_fd);
}

int	main(int argc, char **argv)
{
	int	readelf;
	int	single_file;
	int	i;

	readelf = 0;
	i = 1;
	if (ft_strcmp(argv[argc - 1], "--readelf") == 0)
	{
		argc -= 1;
		readelf = 1;
	}
	if (argc > 2)
		single_file = 0;
	else
		single_file = 1;
	if (argc < 2)
		launch_nm("a.out", single_file, readelf);
	else
	{
		while (i++ < argc)
			launch_nm(argv[i - 1], single_file, readelf);
	}
	return (g_error_count);
}
