FLAGS = -Iinclude/ -lm -std=c99 -c -O3

MATSRC = src/matrix/matrix2.c src/matrix/matrix3.c src/matrix/matrix4.c
VECSRC = src/vector/vector.c src/vector/vector2.c src/vector/vector3.c src/vector/vector4.c src/vector/quaternion.c

MATSRC_PLAIN = src/matrix/matrix2_plain.c src/matrix/matrix3_plain.c src/matrix/matrix4_plain.c
VECSRC_PLAIN = src/vector/vector2_plain.c src/vector/vector3_plain.c src/vector/vector4_plain.c src/vector/quaternion_plain.c

MATINC = include/matrix/matrix2.h include/matrix/matrix3.h include/matrix/matrix4.h
VECINC = include/vector/vector.h include/vector/vector2.h include/vector/vector3.h include/vector/vector4.h include/vector/quaternion.h

MATINC_PLAIN = include/matrix/matrix2_plain.h include/matrix/matrix3_plain.h include/matrix/matrix4_plain.h
VECINC_PLAIN = include/vector/vector2_plain.h include/vector/vector3_plain.h include/vector/vector4_plain.h include/vector/quaternion_plain.h

sse:
	cc $(FLAGS) -msse4.1 $(MATSRC) $(VECSRC)
	ar rcs libglmc.a *.o

	mkdir glmc
	mkdir glmc/matrix glmc/vector
	cp include/defs.h include/glmc.h glmc/
	cp $(MATINC) glmc/matrix
	cp $(VECINC) glmc/vector
	mv libglmc.a glmc

plain:
	cc $(FLAGS) $(MATSRC_PLAIN) $(VECSRC_PLAIN)
	ar rcs libglmc.a *.o

	mkdir glmc
	mkdir glmc/matrix glmc/vector
	cp include/defs_plain.h include/glmc_plain.h glmc/
	cp $(MATINC_PLAIN) glmc/matrix
	cp $(VECINC_PLAIN) glmc/vector
	mv libglmc.a glmc

.PHONY: clean
clean:
	rm *.o
