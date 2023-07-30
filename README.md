# englishnum
A command line tool to convert numbers to English words.

## Requirements
* C++ compiler
* GNU Make

## Installation
Open a terminal to the directory containing the source code and build the program with:
```bash
make
```
The Makefile assumes you have a C++ compiler installed and that it is called 
`g++`. If this is not the case, you can specify the compiler by modifying the 
makefile:
```Makefile
CXX = <compiler>
```
where `<compiler>` is the name of the compiler you wish to use. Then adjust the
`CXXFLAGS` on the next line to ensure that the compiler uses C++14 or greater. 