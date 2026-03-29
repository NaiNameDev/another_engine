RFLGS = -O3 -flto -DNDEBUG=1
DFLGS = -O0
CPP = main.cpp core/*.cpp core/debug/*.cpp physics/*.cpp utils/*.cpp include/glad.c
LIB = -lglfw -lm

a.rel: $(CPP)
	g++ $(RFLGS) $(CPP) -o a.rel $(LIB)

a.dbg: $(CPP)
	g++ $(DFLGS) $(CPP) -o a.dbg $(LIB)

.PHONY = ct c crel

crel: a.rel
	./a.rel
	rm a.rel

ct: a.dbg
	./a.dbg
	rm a.dbg

c: 
	rm a.dbg
