TATGET += $(addprefix bin/, testDef pthread_create getExitCode pthread_exit cleanupPth)

LIBS = -lpthread

all:${TATGET}

bin/testDef:${OBJ_O} src/Chapter_11/testDef.c
	gcc $^ ${D_INC} -o $@

bin/pthread_create:${OBJ_O} src/Chapter_11/pthread_create.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/getExitCode:${OBJ_O} src/Chapter_11/getExitCode.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/pthread_exit:${OBJ_O} src/Chapter_11/pthread_exit.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/cleanupPth:${OBJ_O} src/Chapter_11/cleanupPth.c
	gcc $^ ${LIBS} ${D_INC} -o $@
