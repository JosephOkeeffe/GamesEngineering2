# Joseph O'Keeffe
# 29/9/23
# Licensed under GPLv3

# GPLv3 License

# Lab 2 - D List Code. This lab is about test first prgoramming
# Copyright (c) 2023 Joseph O'Keeffe

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# Git URL - https://github.com/JosephOkeeffe/GamesEngineering2

# Making a variable for all the C FIles in the project
CFILES=listmain.c unittest.c
# Making a variable for all the object files in the project
OBJFILES=listmain.o unittest.o
# Making a variable for all the H files in the project
HFILES=minunit.h DLinkedList.h
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
