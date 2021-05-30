CXXFLAGS := -Wall -pedantic -ansi -std=c++11

OFILESPROJ := $(subst main.o,, $(foreach ofile, $(wildcard ../*.o), $(notdir $(ofile) ) ) )

vpath %.h ../../interface
vpath %.cpp ../../source
vpath %.o ../

areaAir.out: testVerifyAreaAirQuality.o $(OFILESPROJ)
	$(CXX) -o ../$@ $^

airCleaner.out: testCheckImpactAirCleaner.o $(OFILESPROJ)
	$(CXX) -o ../$@ $^

testVerifyAreaAirQuality.o: testVerifyAreaAirQuality.cpp
testCheckImpactAirCleaner.o: testCheckImpactAirCleaner.cpp

clean:
	@rm -rf *.o
