TATGET += $(addprefix bin/, detach recMutex getEnv pthreadSignal atFork)

LIBS = -lpthread

all:${TATGET}

bin/detach:${OBJ_O} src/Chapter_12/detach.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/recMutex:${OBJ_O} src/Chapter_12/recMutex.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/getEnv:${OBJ_O} src/Chapter_12/getEnv.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/pthreadSignal:${OBJ_O} src/Chapter_12/pthreadSignal.c
	gcc $^ ${LIBS} ${D_INC} -o $@

bin/atFork:${OBJ_O} src/Chapter_12/atFork.c
	gcc $^ ${LIBS} ${D_INC} -o $@
