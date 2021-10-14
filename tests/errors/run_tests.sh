#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN}=== TESTING ERROR HANDLING AND SPECIAL CASES ===${NC}\n\n"

printf "> Testing wrong filename\n"

printf " --- NM ---\n"
nm i_dont_exist
printf "Return value: $?\n"
printf " --- FT_NM ---\n"
../.././ft_nm i_dont_exist
printf "Return value: $?\n"

printf "\n> Trying on an empty file\n"
printf " --- NM ---\n"
nm empty
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm empty
printf "Return value: $?\n"

printf "\n> Trying on a file that is less than the 4 bytes of the magic number\n"
printf " --- NM ---\n"
nm small
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm small
printf "Return value: $?\n"

printf "\n> Trying without arguments\n"
printf " --- NM ---\n"
nm
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm
printf "Return value: $?\n"

printf "\n> Trying a file that has wrong architecture (mach-o)\n"
printf " --- NM ---\n"
nm mach-o_binary
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm mach-o_binary
printf "Return value: $?\n"

printf "\n> Trying a file that has wrong architecture (c file)\n"
printf " --- NM ---\n"
nm test_facile.c
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm test_facile.c
printf "Return value: $?\n"

printf "\n> Trying with 1 valid file, 1 non-existent file\n"
printf " --- NM ---\n"
nm ../binary_64/test_facile blabla
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm ../binary_64/test_facile blabla
printf "Return value: $?\n"

printf "\n> Trying with 1 non-existent file, 1 valid file, 1 non-existent file, 1 unauthorized file\n"
printf " --- NM ---\n"
nm hello ../binary_64/test_facile blabla unauthorized
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm hello ../binary_64/test_facile blabla unauthorized
printf "Return value: $?\n"

printf "\n> Trying with an ELF file without symbols\n"
printf " --- NM ---\n"
nm mysql
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm mysql
printf "Return value: $?\n"

printf "\n> Trying with 1 file without symbols, 1 valid file, 1 file without symbols\n"
printf " --- NM ---\n"
nm mysql ../binary_64/test_facile mysql
printf "Return value: $?\n"
printf "\n --- FT_NM ---\n"
../.././ft_nm mysql ../binary_64/test_facile mysql
printf "Return value: $?\n"
