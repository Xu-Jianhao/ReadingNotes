TATGET += $(addprefix bin/, testDef pthread_create getExitCode pthread_exit cleanupPth TestPthr timedlock makeTimeOut)

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

bin/TestPthr:${OBJ_O} src/Chapter_11/TestPthr.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/timedlock:${OBJ_O} src/Chapter_11/timedlock.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/makeTimeOut: src/Chapter_11/makeTimeOut.c
	gcc $^ -o $@

bin/barrierTest:${OBJ_O} src/Chapter_11/barrierTest.c
	gcc $^ ${LIBS} ${D_INC} -o $@
