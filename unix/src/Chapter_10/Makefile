TATGET += $(addprefix bin/,  signalTest alarmTest sleep2 limitRead limitRead2 signalSet)

all:${TATGET}

bin/signalTest:${OBJ_O} src/Chapter_10/signalTest.c
	gcc $^ ${D_INC} -o $@

bin/alarmTest:${OBJ_O} src/Chapter_10/alarmTest.c
	gcc $^ ${D_INC} -o $@
	
bin/sleep2:${OBJ_O} src/Chapter_10/sleep2.c
	gcc $^ ${D_INC} -o $@

bin/limitRead:${OBJ_O} src/Chapter_10/limitRead.c
	gcc $^ ${D_INC} -o $@

bin/limitRead2:${OBJ_O} src/Chapter_10/limitRead2.c
	gcc $^ ${D_INC} -o $@

bin/signalSet:${OBJ_O} src/Chapter_10/signalSet.c
	gcc $^ ${D_INC} -o $@
