#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN}=== TESTS FOR x86_32 binaries ===${NC}\n\n"

bin="test_facile_32"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A very basic x32 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_moins_facile_32"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A basic x32 binary with globals (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="minishell_32"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A more elaborate x32 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="containers_32"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A big x32 binary (C++)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_facile_32 test_moins_facile_32"
nm ${bin} > ./test_results/two_files_nm
../.././ft_nm ${bin} > ./test_results/two_files_ft
a=$(diff ./test_results/two_files_nm ./test_results/two_files_ft)
printf "> [${bin}] : Testing the nm command with several x32 files (2)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_facile_32 test_moins_facile_32 minishell_32"
nm ./${bin} > ./test_results/three_files_nm
../.././ft_nm ./${bin} > ./test_results/three_files_ft
a=$(diff ./test_results/three_files_nm ./test_results/three_files_ft)
printf "> [${bin}] : Testing the nm command with several x32 files (3)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi
