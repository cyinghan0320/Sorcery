CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = a5
OBJECTS = main.o board.o  graveyard.o deck.o player.o hand.o enchantment.o spell.o minion.o rituals.o ascii_graphics.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 -L/opt/X11/lib -I/opt/X11/include

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
