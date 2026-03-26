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

TEST_SOURCES :=
TEST_OBJECTS :=
TEST_HEADERS :=

# headers first
HEADERS += $(wildcard src/*.h)
HEADERS += $(wildcard src/parser/*.h)
HEADERS += $(wildcard src/codegen/*.h)
HEADERS += $(wildcard src/common/*.h)

TEST_HEADERS += $(HEADERS)
TEST_HEADERS += $(wildcard src/tests/*.h)

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

# tests
TEST_SOURCES := $(wildcard src/tests/*.c)
TEST_OBJECTS += $(patsubst src/tests/%.c,obj/tests/%.o,$(wildcard src/tests/*.c))

# wow
$(BBB): $(OBJECTS) | obj build
	$(LD) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo ""
	@echo "Compilation successfull!"
	@echo ""

# src compilation
obj/%.o: src/%.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c $< -o $@

# codegen compilation
obj/codegen/%.o: src/codegen/%.c $(HEADERS) | obj/codegen
	$(CC) $(CFLAGS) -c $< -o $@

# parser compilation
obj/parser/%.o: src/parser/%.c $(HEADERS) | obj/parser
	$(CC) $(CFLAGS) -c $< -o $@

src/parser/rules.tab.c: src/parser/rules.y
	bison -d -o src/parser/rules.tab.c src/parser/rules.y

src/parser/lex.yy.c: src/parser/rules.l
	flex --outfile=src/parser/lex.yy.c src/parser/rules.l

# common compilation
obj/common/%.o: src/common/%.c $(HEADERS) | obj/common
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj build

.PHONY: grammar
grammar:
	bison -d -o src/parser/rules.tab.c src/parser/rules.y
	flex --outfile=src/parser/lex.yy.c src/parser/rules.l

obj:
	mkdir -p $@

obj/codegen:
	mkdir -p $@

obj/parser:
	mkdir -p $@

obj/common:
	mkdir -p $@

obj/tests:
	mkdir -p $@

build:
	mkdir -p $@

build/tests:
	mkdir -p $@

.PHONY: fresh
fresh:
	clear;
	make clean
	make grammar
	make

.PHONY: pt
pt: $(BBB)
	./scripts/pt.sh $(BBB) $(pttest)

# tests?
TEST_BINS := $(patsubst obj/tests/%.o,build/tests/%,$(TEST_OBJECTS))
BBB_LIB := $(filter-out obj/main.o,$(OBJECTS))

# tests compilation
obj/tests/%.o: src/tests/%.c $(TEST_HEADERS) | obj/tests
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BINS): build/tests/% : obj/tests/%.o $(BBB_LIB) | build/tests
	$(LD) $(LDFLAGS) $(LDLIBS) $^ -o $@

.PHONY: tests
tests: $(TEST_BINS)
	@./scripts/tests.sh $^

.PHONY: debug
debug:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@echo HEADERS= $(HEADERS)
	@echo TEST_OBJECTS= $(TEST_OBJECTS)
	@echo TEST_HEADERS= $(TEST_HEADERS)
	@echo TEST_BINS = $(TEST_BINS)
	@echo BBB_LIB = $(BBB_LIB)

