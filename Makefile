MAKEFLAGS += -r

# compiler stuff
CC := gcc
CFLAGS := -Wall -Wextra -O2 -g -std=gnu11

# linker stuff
LD := gcc
LDFLAGS :=
LDLIBS :=

# bbb binary
BBB := build/bbb

# stuff
SOURCES :=
OBJECTS :=
HEADERS :=

# headers first
HEADERS += $(wildcard src/*.h)
HEADERS += $(wildcard src/parser/*.h)
HEADERS += $(wildcard src/common/*.h)

# src
SOURCES += $(wildcard src/*.c)
OBJECTS += $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))

# codegen
SOURCES += $(wildcard src/codegen/*.c)
OBJECTS += $(patsubst src/codegen/%.c,obj/codegen/%.o,$(wildcard src/codegen/*.c))

# parser
SOURCES += $(wildcard src/parser/*.c)
OBJECTS += $(patsubst src/parser/%.c,obj/parser/%.o,$(wildcard src/parser/*.c))

# common
SOURCES += $(wildcard src/common/*.c)
OBJECTS += $(patsubst src/common/%.c,obj/common/%.o,$(wildcard src/common/*.c))

# wow
$(BBB): $(OBJECTS) | obj build
	$(LD) $(LDFLAGS) $(LDLIBS) $^ -o $@

# src compilation
obj/%.o: src/%.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c $< -o $@

# codegen compilation
obj/codegen/%.o: src/codegen/%.c $(HEADERS) | obj/codegen
	$(CC) $(CFLAGS) -c $< -o $@

# parser compilation
obj/parser/%.o: src/parser/%.c $(HEADERS) | obj/parser
	$(CC) $(CFLAGS) -c $< -o $@

# common compilation
obj/common/%.o: src/common/%.c $(HEADERS) | obj/common
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj build

obj:
	mkdir -p $@

obj/codegen:
	mkdir -p $@

obj/parser:
	mkdir -p $@

obj/common:
	mkdir -p $@

build:
	mkdir -p $@

.PHONY: debug
debug:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@echo HEADERS= $(HEADERS)
