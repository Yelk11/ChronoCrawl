SRC_DIR := src
OBJ_DIR := obj


EXE := main
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Iinclude -MMD -MP
CFLAGS += -Wall -g
LIBS = -lncurses

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LIBS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS)  -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)