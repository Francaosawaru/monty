#!/bin/bash
echo -e "\nCompiling monty executable...\n"
gcc *.c -o monty
sleep 1
echo -e "\n============= Monty ===========\n"
./monty test.m
