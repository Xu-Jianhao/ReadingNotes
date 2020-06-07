TATGET += $(addprefix bin/, atexit echoarg printEnv jump longjmp printResLimit)

all:${TATGET}

bin/atexit:${OBJ_O} src/Chapter_7/atexit.c
	gcc $^ ${D_INC} -o $@

bin/echoarg:${OBJ_O} src/Chapter_7/echoarg.c
	gcc $^ ${D_INC} -o $@

bin/printEnv:${OBJ_O} src/Chapter_7/printEnv.c
	gcc $^ ${D_INC} -o $@

bin/jump:${OBJ_O} src/Chapter_7/jump.c
	gcc $^ ${D_INC} -o $@

bin/longjmp:${OBJ_O} src/Chapter_7/longjmp.c
	gcc -O $^ ${D_INC} -o $@

bin/printResLimit:${OBJ_O} src/Chapter_7/printResLimit.c
	gcc -O $^ ${D_INC} -o $@
