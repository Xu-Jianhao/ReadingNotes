TATGET += $(addprefix bin/,  signalTest alarmTest)

all:${TATGET}

bin/signalTest:${OBJ_O} src/Chapter_10/signalTest.c
	gcc $^ ${D_INC} -o $@

bin/alarmTest:${OBJ_O} src/Chapter_10/alarmTest.c
	gcc $^ ${D_INC} -o $@
