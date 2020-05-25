TATGET += $(addprefix bin/, ls_demo printPid likeShell errno printUid)

all:${TATGET}

bin/ls_demo:${OBJ_O} src/Chapter_1/ls_demo.c
	gcc $^ ${D_INC} -o $@

bin/printPid:${OBJ_O} src/Chapter_1/printPid.c
	gcc $^ ${D_INC} -o $@

bin/likeShell:${OBJ_O} src/Chapter_1/likeShell.c
	gcc $^ ${D_INC} -o $@

bin/errno:${OBJ_O} src/Chapter_1/errno.c
	gcc $^ ${D_INC} -o $@

bin/printUid:${OBJ_O} src/Chapter_1/printUid.c
	gcc $^ ${D_INC} -o $@
