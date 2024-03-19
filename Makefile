BUILD_DIR := ./build

clox: $(BUILD_DIR)/main.o $(BUILD_DIR)/memory.o $(BUILD_DIR)/chunk.o $(BUILD_DIR)/debug.o
	gcc -o clox $^

$(OBJDIR)/%.o: %.c %.h common.h
	mkdir -p $(@D)
	gcc -c $< -o $@
