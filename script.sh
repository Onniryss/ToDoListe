#!/bin/bash

if [[ -f "bin/main" ]]; then
    clear

    ./bin/main
else
    echo -e "Compilation failed, check the error logs\n"

fi