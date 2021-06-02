TARGET  := AirWatcher
INCLUDE := interface
SOURCE  := source

CXX := g++
CXXFLAGS := -ansi -pedantic -Wall -std=c++11
LD := g++
LDFLAGS := -g

CPPFILES := $(notdir $(wildcard $(SOURCE)/*.cpp))
HFILES   := $(wildcard $(CURDIR)/$(INCLUDE)/*.h)
OFILES   := $(CPPFILES:%.cpp=%.o)

VPATH := $(CURDIR)/$(SOURCE)


$(TARGET).out : $(OFILES)
	$(LD) $(LDFLAGS) -o $@ $^

$(OFILES) : %.o : %.cpp

$(OFILES) : $(HFILES)

all : $(TARGET).out

# test de la qualité de l'air dans une zone
areaAir:
	$(MAKE) -C tests areaAir.out

# test de l'impact d'un AirCleaner
airCleaner:
	$(MAKE) -C tests airCleaner.out

clean:
	@echo "Nettoyage ..."
	@rm -f *.out *.o

.PHONY: clean all
