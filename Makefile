TARGET  := AirWatcher
INCLUDE := interface
SOURCE  := source

CC := g++
CXXFLAGS := -ansi -pedantic -Wall -std=c++11
LD := $(CC)
LDFLAGS := -g

CPPFILES := $(notdir $(wildcard $(SOURCE)/*.cpp))
HFILES   := $(wildcard $(CURDIR)/$(INCLUDE)/*.h)
OFILES   := $(CPPFILES:%.cpp=%.o)

VPATH := $(CURDIR)/$(SOURCE)


$(TARGET).out : $(OFILES)
	$(LD) $(LDFLAGS) -o $@ $^

$(OFILES) : %.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OFILES) : $(HFILES)

all : $(TARGET).out

clean:
	@echo "Nettoyage ..."
	@rm *.out *.o

.PHONY: clean all
