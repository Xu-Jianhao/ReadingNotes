TATGET += $(addprefix bin/, printFileType umaskTest chmodTest unlinkTest futimensTest foreachDir getcwdTest printDevNum)

all:${TATGET}

bin/printFileType:${OBJ_O} src/Chapter_4/printFileType.c
	gcc $^ ${D_INC} -o $@

bin/umaskTest:${OBJ_O} src/Chapter_4/umaskTest.c
	gcc $^ ${D_INC} -o $@

bin/chmodTest:${OBJ_O} src/Chapter_4/chmodTest.c
	gcc $^ ${D_INC} -o $@

bin/unlinkTest:${OBJ_O} src/Chapter_4/unlinkTest.c
	gcc $^ ${D_INC} -o $@

bin/futimensTest:${OBJ_O} src/Chapter_4/futimensTest.c
	gcc $^ ${D_INC} -o $@

bin/foreachDir:${OBJ_O} src/Chapter_4/foreachDir.c
	gcc $^ ${D_INC} -o $@

bin/getcwdTest:${OBJ_O} src/Chapter_4/getcwdTest.c
	gcc $^ ${D_INC} -o $@

bin/printDevNum:${OBJ_O} src/Chapter_4/printDevNum.c
	gcc $^ ${D_INC} -o $@
