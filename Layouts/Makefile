CC = gcc
CFLAGS = -g -Wall -std=c++17
LDFLAGS=
SOURCES=hello.cpp factorial.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	if [ -d ./objects ] ; then if [ -e ./objects/*.o ] ; then mv ./objects/*.o ; fi ; else mkdir ./objects ; fi ;
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	if [ -e $(TARGET).o ] ; then mv *.o ./objects/ ; fi ;

%.o : %.cpp %.h
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean
clean :
	$(RM) $(TARGET)
	$(RM) -r ./objects
