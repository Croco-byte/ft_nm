/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:58:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 13:00:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELF_H
# define ELF_H

# include <stdint.h>

/* Typedefs for ELF 64 bits */
# define Elf64_Word		uint32_t
# define Elf64_Sword	int32_t
# define Elf64_Half		uint16_t
# define Elf64_Addr		uint64_t
# define Elf64_Off		uint64_t
# define Elf64_Xword	uint64_t
# define Elf64_Section	uint16_t

/* Typedefs for ELF 32 bits */
# define Elf32_Word		uint32_t
# define Elf32_Sword	int32_t
# define Elf32_Half		uint16_t
# define Elf32_Addr		uint32_t
# define Elf32_Off		uint32_t
# define Elf32_Xword	uint64_t
# define Elf32_Section	uint16_t

/* ==== ELF HEADER ==== */

typedef struct {
	unsigned char		e_ident[16];	// Magic number and other infos
	Elf64_Half			e_type;			// File type (executable, shared object...)
	Elf64_Half			e_machine;		// Required architecture (x86, ARM...)
	Elf64_Word			e_version;		// File version
	Elf64_Addr			e_entry;		// Entry point virtual address (or offset for PIC)
	Elf64_Off			e_phoff;		// Program header table offset in file
	Elf64_Off			e_shoff;		// Section header table offset in file
	Elf64_Word			e_flags;		// Processor-specific flags
	Elf64_Half			e_ehsize;		// ELF Header size in bytes
	Elf64_Half			e_phentsize;	// Program Header table entry size
	Elf64_Half			e_phnum;		// Program Header table entry count
	Elf64_Half			e_shentsize;	// Section Header table entry size
	Elf64_Half			e_shnum;		// Section Header table entry count
	Elf64_Half			e_shstrndx;		// Index of header corresponding to the string table containing section names
}						Elf64_Ehdr;

typedef struct {
	unsigned char		e_ident[16];
	Elf32_Half			e_type;
	Elf32_Half			e_machine;
	Elf32_Word			e_version;
	Elf32_Addr			e_entry;
	Elf32_Off			e_phoff;
	Elf32_Off			e_shoff;
	Elf32_Word			e_flags;
	Elf32_Half			e_ehsize;
	Elf32_Half			e_phentsize;
	Elf32_Half			e_phnum;
	Elf32_Half			e_shentsize;
	Elf32_Half			e_shnum;
	Elf32_Half			e_shstrndx;	
}						Elf32_Ehdr;

/* e_ident[<values>] */
# define EI_MAG0					0
# define EI_MAG1					1
# define EI_MAG2					2
# define EI_MAG3					3
# define EI_CLASS					4
# define EI_DATA					5
# define EI_VERSION					6
# define EI_OSABI					7
# define EI_PAD						8

# define ELFMAG0					0x7f
# define ELFMAG1					'E'
# define ELFMAG2					'L'
# define ELFMAG3					'F'
# define ELFMAG						"\177ELF"	// Magic numbers for ELF files

	// Legal values for e_ident[EI_CLASS]
# define ELFCLASSNONE				0			// Invalid
# define ELFCLASS32					1			// ELF32
# define ELFCLASS64					2			// ELF64

	// Legal values for e_ident[EI_DATA]
# define ELFDATANONE				0			// Invalid
# define ELFDATA2LSB				1			// Little-endian architecture
# define ELFDATA2MSB				2			// Big-endian architecture

	// Legal values for e_ident[EI_VERSION]
# define EV_NONE					0
# define EV_CURRENT					1			// Value must be EV_CURRENT

	// Legal values for e_ident[EI_OSABI]		This identifies on which OS the ELF file runs
# define ELFOSABI_SYSV				0
# define ELFOSABI_HPUX				1
# define ELFOSABI_NETBSD			2
# define ELFOSABI_LINUX				3
# define ELFOSABI_SOLARIS			6
# define ELFOSABI_AIX				7
# define ELFOSABI_IRIX				8
# define ELFOSABI_FREEBSD			9
# define ELFOSABI_TRU64				10
# define ELFOSABI_MODESTO			11
# define ELFOSABI_OPENBSD			12
# define ELFOSABI_ARM_AEABI			64
# define ELFOSABI_ARM				97
# define ELFOSABI_STANDALONE		255

/* Legal values for e_type */
# define ET_NONE					0
# define ET_REL						1			// Relocatable file (.o)
# define ET_EXEC					2			// Executable file
# define ET_DYN						3			// Shared object file
# define ET_CORE					4			// Core file

/* Legal values for e_machine */				// Which processor architecture is supported (x86, ARM...)
# define EM_NONE					0
# define EM_SPARC					2
# define EM_386						3
# define EM_PPC64					20
# define EM_ARM						40
# define EM_x86_64					62

/* Legal values for e_version */
# define EV_NONE					0
# define EV_CURRENT					1



/* ==== PROGRAM HEADERS ==== */

typedef struct {
	Elf64_Word			p_type;			// Segment type (loadable...)
	Elf64_Word			p_flags;		// Segment flags (executable | writable | readable)
	Elf64_Off			p_offset;		// Segment offset in file
	Elf64_Addr			p_vaddr;		// Segment virtual address
	Elf64_Addr			p_paddr;		// Segment physical address
	Elf64_Xword			p_filesz;		// Segment size in file
	Elf64_Xword			p_memsz;		// Segment size in memory
	Elf64_Xword			p_align;		// Segment alignment
}						Elf64_Phdr;

typedef struct {
	Elf32_Word			p_type;
	Elf32_Word			p_flags;
	Elf32_Off			p_offset;
	Elf32_Addr			p_vaddr;
	Elf32_Addr			p_paddr;
	Elf32_Word			p_filesz;
	Elf32_Word			p_memsz;
	Elf32_Word			p_align;
}						Elf32_Phdr;

/* Legal values for p_type */
# define PT_NULL			0				// Program header table entry unused
# define PT_LOAD			1				// Loadable program segment
# define PT_DYNAMIC			2				// Dynamic linking informations
# define PT_INTERP			3				// Program interpreter
# define PT_NOTE			4				// Auxiliary informations
# define PT_SHLIB			5				// Reserved
# define PT_PHDR			6				// Entry for header table itself
# define PT_TLS				7				// Thread-local storage segment
# define PT_NUM				8				// Number of defined types
# define PT_LOOS			0x60000000		// Start of OS-Specific segments
# define PT_GNU_EH_FRAME	0x6474e550		// GCC .eh_frame_hdr segment
# define PT_GNU_STACK		0x6474e551		// Indicates stack executability
# define PT_GNU_RELRO		0x6474e552		// Read-only after relocation

/* Legal values for p_flags */
# define PF_X			(1 << 0)			// Executable segment
# define PF_W			(1 << 1)			// Writable segment
# define PF_R			(1 << 2)			// Readable segment


/* ==== SECTION HEADERS ==== */

typedef struct
{
	Elf64_Word			sh_name;			// Section name (index in string table. For example 234 : the name starts at byte 234 in section string table)
	Elf64_Word			sh_type;			// Section type
	Elf64_Xword			sh_flags;			// Section flags
	Elf64_Addr			sh_addr;			// Section virtual address at execution
	Elf64_Off			sh_offset;			// Section offset in file
	Elf64_Xword			sh_size;			// Section size
	Elf64_Word			sh_link;			// Link to another section (for example, sh_link indicates for symtab header the strtab section containing symbol names)
	Elf64_Word			sh_info;			// Additional section information
	Elf64_Xword			sh_addralign;		// Section alignment
	Elf64_Xword			sh_entsize;			// Entry size if section holds table
}						Elf64_Shdr;

typedef struct
{
	Elf32_Word			sh_name;
	Elf32_Word			sh_type;
	Elf32_Word			sh_flags;
	Elf32_Addr			sh_addr;
	Elf32_Off			sh_offset;
	Elf32_Word			sh_size;
	Elf32_Word			sh_link;
	Elf32_Word			sh_info;
	Elf32_Word			sh_addralign;
	Elf32_Word			sh_entsize;
}						Elf32_Shdr;

/* Legal values for sh_type */
# define SHT_NULL				0
# define SHT_PROGBITS			1
# define SHT_SYMTAB				2
# define SHT_STRTAB				3
# define SHT_RELA				4
# define SHT_HASH				5
# define SHT_DYNAMIC			6
# define SHT_NOTE				7
# define SHT_NOBITS				8
# define SHT_REL				9
# define SHT_SHLIB				10
# define SHT_DYNSYM				11
# define SHT_INIT_ARRAY			14
# define SHT_FINI_ARRAY			15
# define SHT_PREINIT_ARRAY		16
# define SHT_GROUP				17
# define SHT_SYMTAB_SHNDX		18
# define SHT_NUM				19
# define SHT_LOOS				0x60000000
# define SHT_GNU_ATTRIBUTES		0x6ffffff5
# define SHT_GNU_HASH			0x6ffffff6
# define SHT_GNU_LIBLIST		0x6ffffff7
# define SHT_GNU_verdef			0x6ffffffd
# define SHT_GNU_verneed		0x6ffffffe
# define SHT_GNU_versym			0x6fffffff

/* Legal values for sh_flags */
# define SHF_WRITE				(1 << 0)
# define SHF_ALLOC				(1 << 1)
# define SHF_EXECINSTR			(1 << 2)
# define SHF_MERGE				(1 << 4)
# define SHF_STRINGS			(1 << 5)
# define SHF_INFO_LINK			(1 << 6)
# define SHF_LINK_ORDER			(1 << 7)
# define SHF_OS_NONCONFORMING	(1 << 8)
# define SHF_GROUP				(1 << 9)
# define SHF_TLS				(1 << 10)
# define SHF_COMPRESSED			(1 << 11)


/* ==== SYMBOL STRUCTURES ==== */
typedef struct
{
	Elf64_Word			st_name;			// Symbol name (symbol strtab index)
	unsigned char		st_info;			// Symbol type and binding
	unsigned char		st_other;			// Symbol visibility
	Elf64_Section		st_shndx;			// Section index
	Elf64_Addr			st_value;			// Section value
	Elf64_Xword			st_size;			// Section size
}						Elf64_Sym;

typedef struct
{
	Elf32_Word			st_name;
	Elf32_Addr			st_value;
	Elf32_Word			st_size;
	unsigned char		st_info;
	unsigned char		st_other;
	Elf32_Section		st_shndx;
}						Elf32_Sym;

/* How to read st_info filed */
# define ELF32_ST_BIND(val)			(((unsigned char) (val)) >> 4)
# define ELF32_ST_TYPE(val)			((val) & 0xf)
# define ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

# define ELF64_ST_BIND(val)			ELF32_ST_BIND(val)
# define ELF64_ST_TYPE(val)			ELF32_ST_TYPE(val)
# define ELF64_ST_INFO(bind, type)	ELF32_ST_INFO((bind), (type))

/* Legal values for ST_BIND subfield of st_info once extracted */
# define STB_LOCAL					0			// Local symbol
# define STB_GLOBAL					1			// Global symbol
# define STB_WEAK					2			// Weak symbol
# define STB_NUM					3			// Number of defined types
# define STB_LOOS					10			// Start of OS specific
# define STB_GNU_UNIQUE				10			// Unique symbol
# define STB_HIOS					12			// End of OS specific
# define STB_LOPROC					13			// Start of processor specific
# define STB_HIPROC					15			// End of processor specific

/* Legal values for ST_TYPE subfield of st_info once extracted */
# define STT_NOTYPE					0			// Symbol type unspecified
# define STT_OBJECT					1			// Symbol is data object
# define STT_FUNC					2			// Symbol is a code object
# define STT_SECTION				3			// Symbol associated with a section
# define STT_FILE					4			// Symbol's name is file name
# define STT_COMMON					5			// Symbol is a common data object
# define STT_TLS					6			// Symbol is a thread-local data object
# define STT_NUM					7			// Number of defined types
# define STT_LOOS					10			// Start of OS specific
# define STT_GNU_IFUNC				10			// Symbol is indirect code object
# define STT_HIOS					12			// End of OS specific
# define STT_LOPROC					13			// Start of processor specific
# define STT_HIPROC					15			// End of processor specific

/* How to read st_other field */
# define ELF32_ST_VISIBILITY(o)		((o) & 0x03)
# define ELF64_ST_VISIBILITY(o)		ELF32_ST_VISIBILITY(o)

/* Legal values for ST_BIND subfield of st_other once extracted */
#define STV_DEFAULT					0			// Default symbol visibility rules
#define STV_INTERNAL				1			// Internal
#define STV_HIDDEN					2			// Hidden
#define STV_PROTECTED				3			// Protected



/* === FATELF STRUCTS === */

# define FATELF_MAGIC		(0x1F0E70FA)

typedef struct FATELF_record
{
	uint16_t				machine;
	uint8_t					osabi;
	uint8_t					osabi_version;
	uint8_t					word_size;
	uint8_t					byte_order;
	uint8_t					reserved0;
	uint8_t					reserved1;
	uint64_t				offset;
	uint64_t				size;
}							FATELF_record;

typedef struct
{
	uint32_t				magic;
	uint16_t				version;
	uint8_t					num_records;
	uint8_t					reserved0;
	FATELF_record			records[0];
}							FATELF_header;
#endif
