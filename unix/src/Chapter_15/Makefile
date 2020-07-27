TATGET += $(addprefix bin/,  pipe pipeAndPager popenAndPager add2 drive_add2 printTypePos useZero)

all:${TATGET}

bin/pipe:${OBJ_O} src/Chapter_15/pipe.c
	gcc $^ ${D_INC} -o $@

bin/pipeAndPager:${OBJ_O} src/Chapter_15/pipeAndPager.c
	gcc $^ ${D_INC} -o $@

bin/popenAndPager:${OBJ_O} src/Chapter_15/popenAndPager.c
	gcc $^ ${D_INC} -o $@

bin/add2:${OBJ_O} src/Chapter_15/add2.c
	gcc $^ ${D_INC} -o $@

bin/drive_add2:${OBJ_O} src/Chapter_15/drive_add2.c
	gcc $^ ${D_INC} -o $@

bin/printTypePos:${OBJ_O} src/Chapter_15/printTypePos.c
	gcc $^ ${D_INC} -o $@

bin/useZero:${OBJ_O} src/Chapter_15/useZero.c
	gcc $^ ${D_INC} -o $@
