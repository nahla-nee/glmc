FLAGS = -lm -std=c99 -c -O3

MATSRC = src/matrix/mat2.c src/matrix/mat3.c src/matrix/mat4.c
VECSRC = src/vector/vec.c src/vector/vec2.c src/vector/vec3.c src/vector/vec4.c src/vector/quat.c

MATINC = include/matrix/
VECINC = include/vector/

glmc:
	cc $(FLAGS) -Iinclude -msse4.1 $(MATSRC) $(VECSRC)
	ar rcs libglmc.a *.o

	mkdir glmc/
	cp $(MATINC) $(VECINC) glmc/ -r
	mv libglmc.a glmc/

.PHONY: clean
clean:
	rm *.o
