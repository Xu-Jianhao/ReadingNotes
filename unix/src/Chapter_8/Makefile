TATGET += $(addprefix bin/,  Fork vFork)

all:${TATGET}

bin/Fork:${OBJ_O} src/Chapter_8/fork.c
	gcc $^ ${D_INC} -o $@

bin/vFork:${OBJ_O} src/Chapter_8/vfork.c
	gcc $^ ${D_INC} -o $@
