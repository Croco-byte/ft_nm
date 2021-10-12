#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

printf "\n\n${CYAN}=== TESTS FOR SHARED OBJECTS (.so) ===${NC}\n\n"

bin="libc-2.27.so"
nm ./${bin} &> ./test_results/${bin}_nm
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : The libc shared library on my system\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="ld-linux-x86-64.so.2"
nm ./${bin} &> ./test_results/${bin}_nm
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : The shared library of the ld linker on my system\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="libEGL.so"
nm ./${bin} &> ./test_results/${bin}_nm
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : Some random shared library used by VS Code\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="libc.so.6"
nm ./${bin} &> ./test_results/${bin}_nm
../.././ft_nm ./${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : Another version of the libc in x64\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="libpthread-2.27.so"
nm ${bin} &> ./test_results/${bin}_nm
../.././ft_nm ${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : The libpthread shared library in x32\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi

bin="_psutil_posix.so"
nm ${bin} &> ./test_results/${bin}_nm
../.././ft_nm ${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A random shared library used by Python 2.7\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi


bin="_padding.abi3.so"
nm ${bin} &> ./test_results/${bin}_nm
../.././ft_nm ${bin} &> ./test_results/${bin}_ft
a=$(diff ./test_results/${bin}_nm ./test_results/${bin}_ft)
printf "> [${bin}] : A random shared library used by Python3\n"
if [[ $a -eq 0 ]]; then
	printf "${GREEN}OK\n\n${NC}"
else
	printf "${RED}KO\n\n${NC}"
fi
