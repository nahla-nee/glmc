FLAGS = -Iinclude/ -lm -std=c99 -c

MATSRC = src/matrix/matrix2.c src/matrix/matrix3.c src/matrix/matrix4.c
VECSRC = src/vector/vector.c src/vector/vector2.c src/vector/vector3.c src/vector/vector4.c

MATSRC_PLAIN = src/matrix/matrix2_plain.c src/matrix/matrix3_plain.c src/matrix/matrix4_plain.c
VECSRC_PLAIN = src/vector/vector2_plain.c src/vector/vector3_plain.c src/vector/vector4_plain.c

sse:
	cc $(FLAGS) -msse4.1 $(MATSRC) $(VECSRC)
	ar rcs libglmc.a *.o

plain:
	cc $(FLAGS) $(MATSRC_PLAIN) $(VECSRC_PLAIN)
	ar rcs libglmc.a *.o

.PHONY: clean
clean:
	rm *.o
