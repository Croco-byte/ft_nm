/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:58:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/11 22:37:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELF
# define ELF

#include <stdint.h>

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

/* Header structure */
typedef struct {
	unsigned char		e_ident[16];			// Magic number and general info
	Elf64_Half			e_type;					// Object file type
	Elf64_Half			e_machine;				// Architecture
	Elf64_Word			e_version;				// Object file version
	Elf64_Addr			e_entry;				// Entry point virtual address
	Elf64_Off			e_phoff;				// Program header table offset
	Elf64_Off			e_shoff;				// Section header table offset
	Elf64_Word			e_flags;				// Processor-specific flags
	Elf64_Half			e_ehsize;				// ELF header size in bytes
	Elf64_Half			e_phentsize;			// Program header table size
	Elf64_Half			e_phnum;				// Program header table count
	Elf64_Half			e_shentsize;			// Section header table size
	Elf64_Half			e_shnum;				// Section header table count
	Elf64_Half			e_shstrndx;				// Section header string table index
}						Elf64_Ehdr;

typedef struct {
	unsigned char		e_ident[16];			// Magic number and general info
	Elf32_Half			e_type;					// Object file type
	Elf32_Half			e_machine;				// Architecture
	Elf32_Word			e_version;				// Object file version
	Elf32_Addr			e_entry;				// Entry point virtual address
	Elf32_Off			e_phoff;				// Program header table offset
	Elf32_Off			e_shoff;				// Section header table offset
	Elf32_Word			e_flags;				// Processor-specific flags
	Elf32_Half			e_ehsize;				// ELF header size in bytes
	Elf32_Half			e_phentsize;			// Program header table size
	Elf32_Half			e_phnum;				// Program header table count
	Elf32_Half			e_shentsize;			// Section header table size
	Elf32_Half			e_shnum;				// Section header table count
	Elf32_Half			e_shstrndx;	
}						Elf32_Ehdr;

/* EI_IDENT */

// Indexes
# define EI_MAG0					0
# define EI_MAG1					1
# define EI_MAG2					2
# define EI_MAG3					3
# define EI_CLASS					4
# define EI_DATA					5
# define EI_VERSION					6
# define EI_OSABI					7
# define EI_PAD						8
// ELF Magic section [0 - 3] values
# define ELFMAG0					0x7f
# define ELFMAG1					'E'
# define ELFMAG2					'L'
# define ELFMAG3					'F'
# define ELFMAG						"\177ELF"
// ELF Class section [4] values
# define ELFCLASSNONE				0		// Invalid
# define ELFCLASS32					1		// 32 bits ELF binary
# define ELFCLASS64					2		// 64 bits ELF binary
// ELF Data section [5] values
# define ELFDATANONE				0		// Invalid
# define ELFDATA2LSB				1		// Little-endian
# define ELFDATA2MSB				2		// Big-endian
// ELF Version section [6] values
# define EV_NONE					0
# define EV_CURRENT					1
// ELF OSABI section [7] values
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


/* E_TYPE */
# define ET_NONE					0			// Invalid
# define ET_REL						1			// .o object files
# define ET_EXEC					2			// binaries
# define ET_DYN						3			// .so shared object
# define ET_CORE					4			// .ko core file


/* E_MACHINE */
# define EM_NONE					0
# define EM_SPARC					2
# define EM_386						3
# define EM_PPC64					20
# define EM_ARM						40
# define EM_x86_64					62


/* E_VERSION */
# define EV_NONE					0
# define EV_CURRENT					1



/* ==== PROGRAM HEADERS ==== */

/* Segment header structure */
typedef struct {
	Elf64_Word			p_type;
	Elf64_Word			p_flags;
	Elf64_Off			p_offset;
	Elf64_Addr			p_vaddr;
	Elf64_Addr			p_paddr;
	Elf64_Xword			p_filesz;
	Elf64_Xword			p_memsz;
	Elf64_Xword			p_align;
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

/* Legal values for p_type (segment type) */
# define PT_NULL			0
# define PT_LOAD			1
# define PT_DYNAMIC			2
# define PT_INTERP			3
# define PT_NOTE			4
# define PT_SHLIB			5
# define PT_PHDR			6
# define PT_TLS				7
# define PT_NUM				8
# define PT_LOOS			0x60000000
# define PT_GNU_EH_FRAME	0x6474e550
# define PT_GNU_STACK		0x6474e551
# define PT_GNU_RELRO		0x6474e552

/* Legal values for p_flags (segment flags) */
# define PF_X			(1 << 0)
# define PF_W			(1 << 1)
# define PF_R			(1 << 2)


/* ==== SECTION HEADERS ==== */

/* Section header structure */

typedef struct
{
	Elf64_Word			sh_name;
	Elf64_Word			sh_type;
	Elf64_Xword			sh_flags;
	Elf64_Addr			sh_addr;
	Elf64_Off			sh_offset;
	Elf64_Xword			sh_size;
	Elf64_Word			sh_link;
	Elf64_Word			sh_info;
	Elf64_Xword			sh_addralign;
	Elf64_Xword			sh_entsize;
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

/* Legal values for sh_flags (section flags) */
# define SHF_WRITE				(1 << 0)
# define SHF_ALLOC				(1 << 1)
# define SHF_EXECINSTR			(1 << 2)
# define SHF_MERGE				(1 << 4)
# define SHF_STRINGS			(1 << 5)
# define SHF_INFO_LINK			(1 << 6)		/* SHT index */
# define SHF_LINK_ORDER			(1 << 7)		/* Preserve order after combining */
# define SHF_OS_NONCONFORMING	(1 << 8)		/* Non-standard OS specific handling required */
# define SHF_GROUP				(1 << 9)		/* Section is member of a group.  */
# define SHF_TLS				(1 << 10)		/* Section hold thread-local data.  */
# define SHF_COMPRESSED			(1 << 11)		/* Section with compressed data. */


/* ==== SYMBOL STRUCTURES ==== */

typedef struct
{
	Elf64_Word			st_name;
	unsigned char		st_info;
	unsigned char		st_other;
	Elf64_Section		st_shndx;
	Elf64_Addr			st_value;
	Elf64_Xword			st_size;
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

/* How to extract and insert information held in the st_info field */
# define ELF32_ST_BIND(val)			(((unsigned char) (val)) >> 4)
# define ELF32_ST_TYPE(val)			((val) & 0xf)
# define ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

# define ELF64_ST_BIND(val)			ELF32_ST_BIND(val)
# define ELF64_ST_TYPE(val)			ELF32_ST_TYPE(val)
# define ELF64_ST_INFO(bind, type)	ELF32_ST_INFO((bind), (type))

/* Legal values for ST_BIND subfield of st_info (symbol binding) */
# define STB_LOCAL					0				/* Local symbol */
# define STB_GLOBAL					1				/* Global symbol */
# define STB_WEAK					2				/* Weak symbol */
# define STB_NUM					3				/* Number of defined types.  */
# define STB_LOOS					10				/* Start of OS-specific */
# define STB_GNU_UNIQUE				10				/* Unique symbol.  */
# define STB_HIOS					12				/* End of OS-specific */
# define STB_LOPROC					13				/* Start of processor-specific */
# define STB_HIPROC					15				/* End of processor-specific */

/* Legal values for ST_TYPE subfield of st_info (symbol type) */
# define STT_NOTYPE					0				/* Symbol type is unspecified */
# define STT_OBJECT					1				/* Symbol is a data object */
# define STT_FUNC					2				/* Symbol is a code object */
# define STT_SECTION				3				/* Symbol associated with a section */
# define STT_FILE					4				/* Symbol's name is file name */
# define STT_COMMON					5				/* Symbol is a common data object */
# define STT_TLS					6				/* Symbol is thread-local data object*/
# define STT_NUM					7				/* Number of defined types.  */
# define STT_LOOS					10				/* Start of OS-specific */
# define STT_GNU_IFUNC				10				/* Symbol is indirect code object */
# define STT_HIOS					12				/* End of OS-specific */
# define STT_LOPROC					13				/* Start of processor-specific */
# define STT_HIPROC					15				/* End of processor-specific */

/* How to extract and insert information held in the st_other field (symbol visibility) */
# define ELF32_ST_VISIBILITY(o)		((o) & 0x03)
# define ELF64_ST_VISIBILITY(o)		ELF32_ST_VISIBILITY(o)

#define STV_DEFAULT					0				/* Default symbol visibility rules */
#define STV_INTERNAL				1				/* Processor specific hidden class */
#define STV_HIDDEN					2				/* Sym unavailable in other modules */
#define STV_PROTECTED				3				/* Not preemptible, not exported */



/* === FATELF STRUCTS === */

# define FATELF_MAGIC		(0x1F0E70FA)

typedef struct FATELF_record
{
	uint16_t				machine;			/* maps to e_machine. */
	uint8_t					osabi;				/* maps to e_ident[EI_OSABI]. */ 
	uint8_t					osabi_version;		/* maps to e_ident[EI_ABIVERSION]. */
	uint8_t					word_size;			/* maps to e_ident[EI_CLASS]. */
	uint8_t					byte_order;			/* maps to e_ident[EI_DATA]. */
	uint8_t					reserved0;
	uint8_t					reserved1;
	uint64_t				offset;
	uint64_t				size;
}							FATELF_record;

typedef struct
{
	uint32_t				magic;				/* always FATELF_MAGIC */
	uint16_t				version;			/* latest is always FATELF_FORMAT_VERSION */
	uint8_t					num_records;
	uint8_t					reserved0;
	FATELF_record			records[0];			/* this is actually num_records items. */
}							FATELF_header;






#endif


/*
Missing NM types :
	> G / g	("initialized data section for small objects")
	> S / s ("uninitialized / 0-initialized data section for small objects")
	> I		("indirect symbol")
	> p (stack unwind section : .eh_frame et .eh_frame_hdr semblent traitées comme des data section)
*/
