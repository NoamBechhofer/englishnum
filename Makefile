# Variables
CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Wextra

# Target application
TARGET = englishnum

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Files and objects
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Make commands
.PHONY: all clean

all: directories $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

directories:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

clean:
	$(RM) $(OBJS) $(BINDIR)/$(TARGET)

