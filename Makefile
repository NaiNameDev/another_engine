FLGS = -O3 -flto
CPP = main.cpp core/*.cpp
LIB = -lglfw -lm

a.elf: $(CPP)
	g++ $(FLGS) $(CPP) -o a.elf $(LIB)

.PHONY = ct c

ct: a.elf
	./a.elf
	rm a.elf

c: 
	rm a.elf
