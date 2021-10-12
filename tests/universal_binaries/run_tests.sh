#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN}=== TESTS FOR FATELF_BINARIES (Linux universal binaries) ===${NC}\n\n"

bin="fatelf_test_facile"
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
printf "> [${bin}] : A FATELF file with test_facile x64 and test_facile x32\n"
printf "${GREEN}OK${NC} (check test_results/fatelf_test_facile_ft)\n\n"

bin="fatelf_test_moins_facile"
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
printf "> [${bin}] : A FATELF file with test_moins_facile x64 and test_moins_facile x32\n"
printf "${GREEN}OK${NC} (check test_results/fatelf_test_moins_facile_ft)\n\n"

bin="fatelf_hard"
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
printf "> [${bin}] : A FATELF file with c++_medium x64 and minishell_32 x32\n"
printf "${GREEN}OK${NC} (check test_results/fatelf_hard_ft)\n\n"
