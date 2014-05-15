
ARCH = $(shell uname)

ifeq ($(ARCH), Darwin)
	CPP = g++
	LINK = g++
else
	CPP = g++
	LINK = g++
endif

CPPFLAGS = -std=c++11 -g -Wno-deprecated
CXXFLAGS = $(shell fltk-config --cxxflags) -I.
LDFLAGS = $(shell fltk-config --ldflags)
LDSTATIC = 


OBJS = 

%.o:	%.cpp %.h
	$(CPP) $(CPPFLAGS) -c $<

calc:	$(OBJS) calc.cpp
	$(LINK) $(CPPFLAGS) calc.cpp $(LDFLAGS) $(OBJS) -o calc

clean:
	rm *.o calc