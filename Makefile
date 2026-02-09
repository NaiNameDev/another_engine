RFLGS = -O3 -flto
DFLGS = -O0
CPP = main.cpp core/*.cpp utils/*.cpp include/glad.c
LIB = -lglfw -lm

a.dbg: $(CPP)
	g++ $(DFLGS) $(CPP) -o a.dbg $(LIB)

a.rel: $(CPP)
	g++ $(RFLGS) $(CPP) -o a.rel $(LIB)

.PHONY = ct c crel

crel: a.rel
	./a.rel
	rm a.rel

ct: a.dbg
	./a.dbg
	rm a.dbg

c: 
	rm a.dbg
