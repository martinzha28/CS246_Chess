CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/opt/X11/lib -lX11 -I/opt/X11/include
EXEC = chess
OBJECTS = main.o Piece.o Board.o Empty.o King.o Knight.o Pawn.o Queen.o Rook.o Bishop.o Player.o Human.o Move.o CPU.o Observer.o Subject.o Textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 -L/opt/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
