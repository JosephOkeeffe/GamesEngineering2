# Joseph O'Keeffe
# 29/9/23
# Licensed under MIT
# (I tried to get the GNU license but I couldn't find out what to copy from the website)
# MIT License

# Copyright (c) 2023 Joseph O'Keeffe

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Git URL - https://github.com/JosephOkeeffe/GamesEngineering2

# Making a variable for all the C FIles in the project
CFILES=stuff.c 
# Making a variable for all the object files in the project
OBJFILES=stuff.o
# Making a variable for all the H files in the project
HFILES=minunit.h
# Making a variable for the compilers in the project
CC= gcc
# Making a variable for  the executable in the project
EXEFILE=exe
# Making a variable for all the flags in the project
FLAGS= -Wall -g -O0

# Builds object files from corresponding C files
%.o: %.c
#
	$(CC) -Wall -c $< -o $@ 

# This builds the final executable from the object and header files
EXE: $(OBJFILES) $(HFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(EXEFILE)

# This is used to clean up the project by removing all object *.o files
CLEAN: 
	rm *.o

# This is used to install the executable file to a specific location
INSTALL:
	cp $(EXEFILE) home/osboxes/bin/