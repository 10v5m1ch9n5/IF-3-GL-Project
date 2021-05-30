CXXFLAGS := -Wall -pedantic -ansi -std=c++11

OFILESPROJ := $(subst main.o,, $(foreach ofile, $(wildcard ../*.o), $(notdir $(ofile) ) ) )

vpath %.h ../../interface
vpath %.cpp ../../source
vpath %.o ../

pointAir.out: testVerifyPointAirQuality.o $(OFILESPROJ)
	$(CXX) -o ../$@ $^

areaAir.out: testVerifyAreaAirQuality.o $(OFILESPROJ)
	$(CXX) -o ../$@ $^

testVerifyPointAirQuality.o: testVerifyPointAirQuality.cpp
testVerifyAreaAirQuality.o: testVerifyAreaAirQuality.cpp

clean:
	@rm -rf *.o *.out
