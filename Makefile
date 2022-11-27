CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/opt/X11/lib -lX11 -I/opt/X11/include
EXEC = chess
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 -L/opt/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}