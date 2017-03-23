CODEINFO = -DCODEFLAG="\"official version\"" \
	   -DCODEMAJORVER=1 \
	   -DCODEMINORVER=1 \
	   -DCODEUSER="\"`whoami | sed 's/\\\\/\\\\\\\\/g'`\"" \
	   -DCODEMACHINE="\"`hostname`\"" \
	   -DCODECOMPILER="\"$(CXX)"\" \
           -DCODECOMPFLAG="\"$(CXXFLAG)"\" \
	   -DCODELINUX

CXX     = g++
CXXFLAG =-O3 --std=c++0x  #-Wall -Wno-unknown-pragmas -Wno-sign-compare -Wno-unused -g 
CC      = gcc
CCFLAG  =-O3 -fopenmp -Wall # -g -o segfault

INCDIR  =./include
SRCS    =./src
BINS    =./bin
INCS    =-I$(INCDIR) -I$(SRCS)
OBJS    =./obj
DEPS    =./depend

TARGET   = $(BINS)/main
SOURCES := $(wildcard $(SRCS)/*.cpp)
OBJECTS := $(patsubst $(SRCS)%.cpp,$(OBJS)%.o,$(SOURCES))    

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAG) $(INCS) $(LIBS) -o $@ $^


sinclude $(patsubst $(SRCS)%.cpp,$(DEPS)%.d,$(SOURCES))

$(OBJS)/%.o: $(SRCS)/%.cpp
	$(CXX) $(CXXFLAG) $(CODEINFO) $(INCS) $(LIBS) -c -o $@ $<


$(DEPS)/%.d: $(SRCS)/%.cpp
	@set -e; \
	rm -f $@; \
	$(CXX) -MM $(CXXFLAG) $(CODEINFO) $(INCS) $< > $@.$$$$;\
	sed 's/\([a-zA-Z0-9]*\)\.o[ :]/$(patsubst ./%,%,$(OBJS)\/$(shell v1=$@; v2=$${v1%/*}; v3=$${v2#*/}; echo $${v3} | sed 's/\//\\\//g'))\/\1.o $(patsubst ./%,%,$(DEPS)\/$(shell v1=$@; v2=$${v1%/*}; v3=$${v2#*/}; echo $${v3} | sed 's/\//\\\//g'))\/\1.d:/g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(TARGET) $(DEPS)/*.d* src/*~
