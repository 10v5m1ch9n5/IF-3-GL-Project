CXXFLAGS := -Wall -pedantic -ansi -std=c++11

OFILESPROJ := $(subst main.o,, $(foreach ofile, $(wildcard ../*.o), $(notdir $(ofile) ) ) )

vpath %.h ../../interface
vpath %.cpp ../../source
vpath %.o ../

testVerifyPointAirQuality.out: testVerifyPointAirQuality.o $(OFILESPROJ)
	$(CXX) -o $@ $^

testVerifyPointAirQuality.o: testVerifyPointAirQuality.cpp

$(OFILESPROJ):
	echo "fichiers .o de AirWatcher non disponibles"

clean:
	@rm -rf *.o *.out
