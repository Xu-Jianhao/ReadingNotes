TATGET += $(addprefix bin/, printFileType umaskTest chmodTest unlinkTest)

all:${TATGET}

bin/printFileType:${OBJ_O} src/Chapter_4/printFileType.c
	gcc $^ ${D_INC} -o $@

bin/umaskTest:${OBJ_O} src/Chapter_4/umaskTest.c
	gcc $^ ${D_INC} -o $@

bin/chmodTest:${OBJ_O} src/Chapter_4/chmodTest.c
	gcc $^ ${D_INC} -o $@

bin/unlinkTest:${OBJ_O} src/Chapter_4/unlinkTest.c
	gcc $^ ${D_INC} -o $@
