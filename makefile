CC				:= g++
CFLAGS			:= -I/usr/include/opencv
SRCDIR			:= ./src
OBJECTS			:= ./bin/logo
LIBRARIES       := -lml -lcvaux -lhighgui -lcv -lcxcore

RM= rm -f

all: findlogo

findlogo:
			$(CC) -g -o $(OBJECTS) ./src/logo.cpp $(CFLAGS) $(LIBRARIES)

clean:
		$(RM) ./bin/*