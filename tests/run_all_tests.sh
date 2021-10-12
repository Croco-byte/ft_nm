#!/bin/bash

cd ./binary_64 && ./run_tests.sh
cd ../binary_32 && ./run_tests.sh
cd ../object_files && ./run_tests.sh
cd ../shared_objects && ./run_tests.sh
cd ../universal_binaries && ./run_tests.sh
cd ../errors && ./run_tests.sh
