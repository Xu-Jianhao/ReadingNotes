TATGET += $(addprefix bin/, unix_poll_C unix_poll_S unixExample)

all:${TATGET}

bin/unix_poll_C:${OBJ_O} src/Chapter_17/unix_poll_C.c
	gcc $^ ${D_INC} -o  $@

bin/unix_poll_S:${OBJ_O} src/Chapter_17/unix_poll_S.c
	gcc $^ ${D_INC} -lpthread -o $@

bin/unixExample:${OBJ_O} src/Chapter_17/unixExample.c
	gcc $^ ${D_INC} -o  $@
