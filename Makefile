MAKEFLAGS += -r

CC := gcc
CFLAGS := -Wall -Wextra -O0 -g -std=gnu11 -fno-pie

LD := gcc
LDFLAGS := -rdynamic -g -no-pie
LDLIBS :=

BBB := build/bbb

SOURCES :=
OBJECTS :=
HEADERS :=

TEST_SOURCES :=
TEST_OBJECTS :=
TEST_HEADERS :=

GEN_C := src/parser/rules.tab.c src/parser/lex.yy.c
GEN_H := src/parser/rules.tab.h

HEADERS += $(wildcard src/*.h)
HEADERS += $(wildcard src/parser/*.h) $(GEN_H)
HEADERS += $(wildcard src/codegen/*.h)
HEADERS += $(wildcard src/common/*.h)
HEADERS := $(sort $(HEADERS))

TEST_HEADERS += $(HEADERS)
TEST_HEADERS += $(wildcard src/tests/*.h)

SOURCES += $(wildcard src/*.c)
OBJECTS += $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))

SOURCES += $(wildcard src/codegen/*.c)
OBJECTS += $(patsubst src/codegen/%.c,obj/codegen/%.o,$(wildcard src/codegen/*.c))

PARSER_SRCS := $(wildcard src/parser/*.c) $(GEN_C)
SOURCES += $(sort $(PARSER_SRCS))
OBJECTS += $(patsubst src/parser/%.c,obj/parser/%.o,$(sort $(PARSER_SRCS)))

SOURCES += $(wildcard src/common/*.c)
OBJECTS += $(patsubst src/common/%.c,obj/common/%.o,$(wildcard src/common/*.c))

TEST_SOURCES := $(wildcard src/tests/*.c)
TEST_OBJECTS += $(patsubst src/tests/%.c,obj/tests/%.o,$(wildcard src/tests/*.c))

$(BBB): $(OBJECTS) | obj build
	$(LD) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo ""
	@echo "Compilation successfull!"
	@echo ""

obj/%.o: src/%.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/codegen/%.o: src/codegen/%.c $(HEADERS) | obj/codegen
	$(CC) $(CFLAGS) -c $< -o $@

obj/parser/%.o: src/parser/%.c $(HEADERS) | obj/parser
	$(CC) $(CFLAGS) -c $< -o $@

src/parser/rules.tab.c src/parser/rules.tab.h: src/parser/rules.y
	bison -d -o src/parser/rules.tab.c src/parser/rules.y

src/parser/lex.yy.c: src/parser/rules.l src/parser/rules.tab.h
	flex --outfile=src/parser/lex.yy.c src/parser/rules.l

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

RT_TEST_DIRS = $(wildcard rt/*/)

.PHONY: rt $(RT_TEST_DIRS)
rt: $(RT_TEST_DIRS)

$(RT_TEST_DIRS): $(BBB)
	@echo "--- Running test $@ ---"
	@make --no-print-directory -C $@ verify

TEST_BINS := $(patsubst obj/tests/%.o,build/tests/%,$(TEST_OBJECTS))
BBB_LIB := $(filter-out obj/main.o,$(OBJECTS))

obj/tests/%.o: src/tests/%.c $(TEST_HEADERS) $(BBB_LIB) | obj/tests
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BINS): build/tests/% : obj/tests/%.o $(BBB_LIB) | build/tests
	$(LD) $(LDFLAGS) $(LDLIBS) $^ -o $@

.PHONY: tests
tests: $(TEST_BINS)
	@./scripts/tests.sh build/tests $(test)

.PHONY: debug
debug:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@echo HEADERS= $(HEADERS)
	@echo TEST_OBJECTS= $(TEST_OBJECTS)
	@echo TEST_HEADERS= $(TEST_HEADERS)
	@echo TEST_BINS = $(TEST_BINS)
	@echo BBB_LIB = $(BBB_LIB)
