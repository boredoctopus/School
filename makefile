# Sample makefile
# for building two sample applications
# week 1
# 

# MACRO VARIABLES
# program for compiling C++ files
CXX=CL

# EXTRA FLAGS FOR C++ compiler
# Za = ANSI C, no microsoft extensions
# W4 = highest level of warnings
CXXFLAGS=/c /Od /EHsc /nologo /W4 /Za /FAscu
# no include directories specified
INCS=
# no CPP variable settings specified
CXXVARS=

# linker command, with flags
LINK=LINK
LFLAGS=/NOLOGO /MAP
# map option gives large detail on program being linked
# specify verbose to see linker operation in detail /VERBOSE

LVARS=
# path to libraries
LPATHS=
# libraries
LIBS=

# program for removing a file
RM=del

# binary runtime program(s)
BINS=main.exe conversion.exe first.exe
# object modules
OBJS=main.obj conversion.obj first.obj

# MAKEFILE TARGETS 
# first target is default
ALL: $(OBJS) $(BINS)

# (RE)DEFINE (IMPLICIT) PATTERN RULE 1 (making obj (TARGET) files from cpp (DEPENDENT) files - COMPILER)
# to make a .obj file from a .cpp file, issue the following COMMAND
# (Note: $* is current target minus cpp extension)
.cpp.obj:
	$(CXX) $(CXXFLAGS) $(INCS) $(CVARS) $*.cpp

# (RE)DEFINE (IMPLICIT) PATTERN RULE 2 (making exe (TARGET) files from single obj (DEPENDENT) files - LINKER)
# to make a .exe file from a .obj file, issue the following COMMAND
# (Note: $@ is full current target i.e. path,base name, and extension)
.obj.exe:
	$(LINK) $*.obj $(LFLAGS) $(LVARS) /OUT:$@ $(LPATHS) $(LIBS)

# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Main program - 3 dependencies
# 1) Main.obj is dependent on changes to HEADER file (compiler) 
# 2) Main.obj is dependent on changes to CPP file (compiler)
# 3) Main.exe is dependent on changes to OBJ file (linker)

# RULE: Dep (3) (USE PATTERN RULE 2)
# Main.exe is dependent on Main.obj
main.exe: main.obj

# RULE: Dep (2) (USE PATTERN RULE 1)
# main.obj is dependent on Main.cpp, and Association.h
main.obj: main.cpp association.h

# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Main program - 2 dependencies
# 1) Conversion.obj is dependent on changes to CPP file (compiler)
# 2) Conversion.exe is dependent on changes to OBJ file (linker)

# Conversion.obj is dependent on cpp file
conversion.obj: conversion.cpp 

conversion.exe: conversion.obj


# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Main program - 3 dependencies
# 1) First.obj is dependent on changes to CPP file (compiler)
# 2) First.exe is dependent on changes to OBJ file (linker)
first.obj: first.cpp 

first.exe: first.obj

# when removing 'cleaning' remove only object and executable files
clean:
	$(RM) $(OBJS)
	$(RM) $(BINS)
	$(RM) main.map
	$(RM) main.cod
	$(RM) conversion.map
	$(RM) conversion.cod
	$(RM) first.map
	$(RM) first.cod
	$(RM) *.???~
	$(RM) *~


