CXX = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17 -fPIC -DLAYOUTS_EXPORTS
LDFLAGS =
EXECUTABLE = Layouts.so
SOURCES = Layouts.cpp LayoutPoint.cpp LayoutSize.cpp LayoutRect.cpp LayoutMargins.cpp LayoutItem.cpp LayoutGroup.cpp LayoutControl.cpp
OBJECTS=$(SOURCES:.cpp=.o)

# Build Steps
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) --shared -o $@

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -c $@

.PHONY: clean
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)