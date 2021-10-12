#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN} === TESTS FOR x86_64 binaries ===${NC}\n\n"

bin="test_facile"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A very basic x64 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_moins_facile"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A basic x64 binary with globals (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="cub3D"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A more elaborate x64 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="gnl"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A more elaborate x64 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="big_bin"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A big x64 binary (C)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="c++_medium"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A medium x64 binary (C++)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="webserv"
nm ./${bin} > ./test_results/${bin}_nm
../.././ft_nm ./${bin} > ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A big x64 binary (C++)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_facile test_moins_facile"
nm ${bin} > ./test_results/two_files_nm
../.././ft_nm ${bin} > ./test_results/two_files_ft
a=$(diff ./test_results/two_files_nm ./test_results/two_files_ft)
printf "> [${bin}] : Testing the nm command with several x64 files (2)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="test_facile test_moins_facile c++_medium"
nm ./${bin} > ./test_results/three_files_nm
../.././ft_nm ./${bin} > ./test_results/three_files_ft
a=$(diff ./test_results/three_files_nm ./test_results/three_files_ft)
printf "> [${bin}] : Testing the nm command with several x64 files (3)\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi
