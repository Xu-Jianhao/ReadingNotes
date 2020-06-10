TATGET += $(addprefix bin/,  Fork vFork printExit waitpid 8.9test execExample systemTest niceTest timesTest)

all:${TATGET}

bin/Fork:${OBJ_O} src/Chapter_8/fork.c
	gcc $^ ${D_INC} -o $@

bin/vFork:${OBJ_O} src/Chapter_8/vfork.c
	gcc $^ ${D_INC} -o $@

bin/printExit:${OBJ_O} src/Chapter_8/printExit.c
	gcc $^ ${D_INC} -o $@

bin/waitpid:${OBJ_O} src/Chapter_8/waitpid.c
	gcc $^ ${D_INC} -o $@

bin/8.9test:${OBJ_O} src/Chapter_8/8.9test.c
	gcc $^ ${D_INC} -o $@

bin/execExample:${OBJ_O} src/Chapter_8/execExample.c
	gcc $^ ${D_INC} -o $@

bin/systemTest:${OBJ_O} src/Chapter_8/systemTest.c
	gcc $^ ${D_INC} -o $@

bin/niceTest:${OBJ_O} src/Chapter_8/niceTest.c
	gcc $^ ${D_INC} -o $@

bin/timesTest:${OBJ_O} src/Chapter_8/timesTest.c
	gcc $^ ${D_INC} -o $@
