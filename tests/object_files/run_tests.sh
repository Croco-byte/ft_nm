#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN}=== TESTS FOR OBJECT FILES ===${NC}\n\n"

bin="test_facile_x32.o"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A very basic x32 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_moins_facile_x32.o"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A basic x32 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_facile_x64.o"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A very basic x64 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_moins_facile_x64.o"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A basic x64 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="cub3D_utils_x64.o"
nm ${bin} > ./test_results/${bin}_nm
../.././ft_nm ${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A more elaborate x64 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="containers_main_x32.o"
nm ${bin} > ./test_results/${bin}_nm
../.././ft_nm ${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : An elaborate x32 object file\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi
