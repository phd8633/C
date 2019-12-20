#########################################################################
# File Name: makefile.sh
# Author: phd
# mail: panhd@neusoft.com
# Created Time: Thu 05 Dec 2019 11:39:29 PM PST
#########################################################################
#!/bin/bash
gcc WriteNamePipe.c -o WriteNamePipe.out
gcc ReadNamePipe.c -o  ReadNamePipe.out
./ReadNamePipe.out &
./WriteNamePipe.out
