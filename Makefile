BUILD := ./build
SRC := ./src

CFLAGS = -Wall
MKDIR_P = mkdir -p

# All .c files in the source dir
SRCS = $(wildcard $(SRC)/*.c)

# Replaces SRC with BUILD for each file in SRCS
OBJS = $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRCS))

.DEFAULT_GOAL := clox

# Builds clox
clox: $(OBJS) | $(BUILD)
	$(CC) $(LDFLAGS) -o $(BUILD)/$@ $^

# Builds object files from corresponding sources in SRC
# Specifies dependency on source file $< and target object file $@
$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

# Prereq that ensures build dir is present
$(BUILD):
	$(MKDIR_P) $(BUILD)

# Builds and runs clox binary
.PHONY: run
run:
	@$(MAKE) -s
	@$(BUILD)/clox

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: clobber
clobber:
	$(RM) -r $(BUILD)

