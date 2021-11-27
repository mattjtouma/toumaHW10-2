#!/bin/bash

# Echo a message
echo "Compiling..."

# Set the pinmode for p8.16
config-pin -a p8.16 in+

# Compile read_button.cpp
g++ read_button.cpp GPIO.cpp -o read_button.cgi -lcgicc -lpthread

echo "done"
