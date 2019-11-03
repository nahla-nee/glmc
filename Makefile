FLAGS = -lm -std=c99 -c -O3

MATSRC = simd/src/matrix/mat2.c simd/src/matrix/mat3.c simd/src/matrix/mat4.c
VECSRC = simd/src/vector/vec.c simd/src/vector/vec2.c simd/src/vector/vec3.c simd/src/vector/vec4.c simd/src/vector/quat.c

MATSRC_PLAIN = plain/src/matrix/mat2.c plain/src/matrix/mat3.c plain/src/matrix/mat4.c
VECSRC_PLAIN = plain/src/vector/vec2.c plain/src/vector/vec3.c plain/src/vector/vec4.c plain/src/vector/quat.c

MATINC = simd/include/matrix/
VECINC = simd/include/vector/

MATINC_PLAIN = plain/include/matrix/
VECINC_PLAIN = plain/include/vector/

glmc-simd:
	cc $(FLAGS) -Isimd/include -msse4.1 $(MATSRC) $(VECSRC)
	ar rcs libglmc.a *.o

	mkdir glmc-simd
	cp $(MATINC) $(VECINC) glmc-simd -r
	mv libglmc.a glmc-simd/libglmc.a

glmc-plain:
	cc $(FLAGS) -Iplain/include $(MATSRC_PLAIN) $(VECSRC_PLAIN)
	ar rcs libglmc.a *.o

	mkdir glmc-plain
	cp $(MATINC_PLAIN) $(VECINC_PLAIN) glmc-plain -r
	mv libglmc.a glmc-plain/libglmc.a

.PHONY: clean
clean:
	rm *.o
