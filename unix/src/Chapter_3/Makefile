TATGET += $(addprefix bin/, lseekTest createEmptyFile printFileFlag)

all:${TATGET}

bin/lseekTest:${OBJ_O} src/Chapter_3/lseekTest.c
	gcc $^ ${D_INC} -o $@

bin/createEmptyFile:${OBJ_O} src/Chapter_3/createEmptyFile.c
	gcc $^ ${D_INC} -o $@

bin/printFileFlag:${OBJ_O} src/Chapter_3/printFileFlag.c
	gcc $^ ${D_INC} -o $@
