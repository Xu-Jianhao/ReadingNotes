TATGET += $(addprefix bin/, noBlockWrite deadflock mmap)

all:${TATGET}

bin/noBlockWrite:${OBJ_O} src/Chapter_14/noBlockWrite.c
	gcc $^ ${D_INC} -o $@

bin/deadflock:${OBJ_O} src/Chapter_14/deadflock.c
	gcc $^ ${D_INC} -o $@

bin/mmap:${OBJ_O} src/Chapter_14/mmap.c
	gcc $^ ${D_INC} -o $@
