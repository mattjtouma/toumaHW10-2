#!/bin/bash

# Copy the read_button executable to the cgicc directory
echo "Copying the application to the cgi-bin directory..."
sudo cp read_button.cgi /usr/lib/cgi-bin/

# Set permissions
echo "Setting permissions..."
sudo chmod +s /usr/lib/cgi-bin/read_button.cgi
echo "success"
