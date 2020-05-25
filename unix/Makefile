D_SRC = src
D_INC = -I ./include
D_OBJ = lib
D_BIN = bin

SRC_C  = $(wildcard $(D_SRC)/*.c)
OBJ_O  = $(addprefix $(D_OBJ)/, $(patsubst %.c,%.o,$(notdir $(SRC_C))))

.PHONY: all clean

include src/Chapter_1/Makefile

$(info SRC_C is ${SRC_C})

all: $(TATGET)

$(D_OBJ)/%.o: $(D_SRC)/%.c
	gcc -c -Wall $(D_INC) $< -o $@


clean:
	rm -f $(D_OBJ)/* $(TATGET)
