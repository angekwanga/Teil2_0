# Makefile for GTFS Qt Application

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
QTFLAGS = $(shell pkg-config --cflags Qt5Widgets Qt5Core Qt5Gui)
QTLIBS = $(shell pkg-config --libs Qt5Widgets Qt5Core Qt5Gui)

# List of source files without main.cpp for testing
LIB_SOURCES = network.cpp

# Main application
SOURCES = main.cpp mainwindow.cpp $(LIB_SOURCES)
HEADERS = mainwindow.h network.h types.h

# Objects for application
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = gtfs_search

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(QTFLAGS) $(OBJECTS) -o $@ $(QTLIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(QTFLAGS) -c $< -o $@

# Generate Makefile for Qt project
qmake:
	qmake project.pro

# Create a version for autotesting
autotest:
	g++ -I. -I/usr/local/include -std=c++17 -o /repo/test_runner /tester.cpp /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a $(LIB_SOURCES)

clean:
	rm -f $(OBJECTS) $(TARGET) *~

.PHONY: all clean qmake autotest