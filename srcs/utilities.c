/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:00:30 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 12:11:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	which_elf(unsigned char class)
{
	if (class == ELFCLASS32)
		return (0);
	else if (class == ELFCLASS64)
		return (1);
	else
		return (-1);
}

void	print_machine(uint16_t flag)
{
	if (flag == EM_NONE)
		printf("None");
	else if (flag == EM_SPARC)
		printf("SPARC");
	else if (flag == EM_386)
		printf("Intel x86");
	else if (flag == EM_PPC64)
		printf("PowerPC 64");
	else if (flag == EM_ARM)
		printf("ARM");
	else if (flag == EM_x86_64)
		printf("Advanced Micro Devices X86-64");
	else
		printf("Unknown");
}
