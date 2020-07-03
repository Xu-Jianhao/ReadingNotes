TATGET += $(addprefix bin/, daemonize1)

all:${TATGET}

bin/daemonize1:${OBJ_O} src/Chapter_13/daemonize.c
	gcc $^ ${D_INC} -o $@
