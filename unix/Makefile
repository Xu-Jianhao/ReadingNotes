D_SRC = src
D_INC = -I ./include
D_OBJ = lib
D_BIN = bin
SRC_C  = $(wildcard $(D_SRC)/*.c)
OBJ_O  = $(addprefix $(D_OBJ)/, $(patsubst %.c,%.o,$(notdir $(SRC_C))))

include src/Chapter_1/Makefile
include src/Chapter_2/Makefile
include src/Chapter_3/Makefile
include src/Chapter_4/Makefile
include src/Chapter_5/Makefile
include src/Chapter_6/Makefile
include src/Chapter_7/Makefile

$(info TATGET is ${TATGET})

$(D_OBJ)/%.o: $(D_SRC)/%.c
	gcc -c -Wall $(D_INC) $< -o $@

.PHONY: clean

clean:
	rm -f $(D_OBJ)/* $(TATGET)
