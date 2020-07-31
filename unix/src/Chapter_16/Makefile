TATGET += $(addprefix bin/, getAddrInfo ruptime_TCP_C ruptime_TCP_S ruptime_TCP_S_2 ruptime_UDP_C ruptime_UDP_S)

all:${TATGET}

bin/getAddrInfo:${OBJ_O} src/Chapter_16/getAddrInfo.c
	gcc $^ ${D_INC} -o $@

bin/ruptime_TCP_C:${OBJ_O} src/Chapter_16/ruptime_TCP_C.c
	gcc $^ ${D_INC} -o $@

bin/ruptime_TCP_S:${OBJ_O} src/Chapter_16/ruptime_TCP_S.c
	gcc $^ ${D_INC} -o $@

bin/ruptime_TCP_S_2:${OBJ_O} src/Chapter_16/ruptime_TCP_S_2.c
	gcc $^ ${D_INC} -o $@

bin/ruptime_UDP_C:${OBJ_O} src/Chapter_16/ruptime_UDP_C.c
	gcc $^ ${D_INC} -o $@

bin/ruptime_UDP_S:${OBJ_O} src/Chapter_16/ruptime_UDP_S.c
	gcc $^ ${D_INC} -o $@
