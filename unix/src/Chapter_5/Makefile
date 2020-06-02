TATGET += $(addprefix bin/, getc_putc fgets_fputs printStdioCached tmpfile mkstemp memoryStream)

all:${TATGET}

bin/getc_putc:${OBJ_O} src/Chapter_5/getc_putc.c
	gcc $^ ${D_INC} -o $@

bin/fgets_fputs:${OBJ_O} src/Chapter_5/fgets_fputs.c
	gcc $^ ${D_INC} -o $@

bin/printStdioCached:${OBJ_O} src/Chapter_5/printStdioCached.c
	gcc $^ ${D_INC} -o $@

bin/tmpfile:${OBJ_O} src/Chapter_5/tmpfile.c
	gcc $^ ${D_INC} -o $@

bin/mkstemp:${OBJ_O} src/Chapter_5/mkstemp.c
	gcc $^ ${D_INC} -o $@

bin/memoryStream:${OBJ_O} src/Chapter_5/memoryStream.c
	gcc $^ ${D_INC} -o $@
