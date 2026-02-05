RFLGS = -O3 -flto
DFLGS = -Wall -Wextra -pedantic -O2
CPP = main.cpp core/*.cpp include/glad.c
LIB = -lglfw -lm

a.dbg: $(CPP)
	g++ $(DFLGS) $(CPP) -o a.dbg $(LIB)

a.rel: $(CPP)
	g++ $(RFLGS) $(CPP) -o a.rel $(LIB)

.PHONY = ct c crel

rel: a.rel
	./a.rel
	rm a.rel

ct: a.dbg
	./a.dbg
	rm a.dbg

c: 
	rm a.dbg
