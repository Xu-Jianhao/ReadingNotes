TATGET += $(addprefix bin/,  signalTest alarmTest sleep2 limitRead limitRead2 signalSet sigsetjmp sigsuspend sigsuspend2 systemTT SIGTSTP)

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

bin/sigsetjmp:${OBJ_O} src/Chapter_10/sigsetjmp.c
	gcc $^ ${D_INC} -o $@

bin/sigsuspend:${OBJ_O} src/Chapter_10/sigsuspend.c
	gcc $^ ${D_INC} -o $@

bin/sigsuspend2:${OBJ_O} src/Chapter_10/sigsuspend2.c
	gcc $^ ${D_INC} -o $@

bin/systemTT:${OBJ_O} src/Chapter_10/systemTT.c
	gcc $^ ${D_INC} -o $@

bin/SIGTSTP:${OBJ_O} src/Chapter_10/SIGTSTP.c
	gcc $^ ${D_INC} -o $@
