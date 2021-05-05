TARGET  := AirWatcher
INCLUDE := interface
SOURCE  := source
BUILD   := build

CC := g++
CXXFLAGS := -ansi -pedantic -Wall -std=c++11
LD := $(CC)
LDFLAGS := -g

CPPFILES := $(notdir $(wildcard $(SOURCE)/*.cpp))
HFILES   := $(wildcard $(CURDIR)/$(INCLUDE)/*.h)
OFILES   := $(CPPFILES:%.cpp=%.o)

VPATH := $(SOURCE)


$(TARGET).out : $(OFILES)
	$(LD) $(LDFLAGS) -o $@ $^

$(OFILES) : %.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OFILES) : $(HFILES)

all : $(TARGET).out

clean:
	@rm *.out *.o

.PHONY: clean all