BBB = ../../build/bbb

OBJ = $(patsubst %.bbb,%.o,$(wildcard *.bbb))
OBJ += $(patsubst %.nasm,%.o,$(wildcard *.nasm))
OBJ += $(patsubst %.c,%.o,$(wildcard *.c))

main.bin: $(OBJ)
	gcc -g $(OBJ) -o $@

%.o: %.basm
	nasm -g -F dwarf -f elf64 $< -o $@

%.o: %.nasm
	nasm -g -F dwarf -f elf64 $< -o $@

%.o: %.c
	gcc -g $< -o $@

.PRECIOUS: %.basm
%.basm: %.bbb $(BBB)
	$(BBB) -vvvvPlce $< -o $@

.PHONY: clean
clean:
	rm $(OBJ) $(wildcard *.basm)

.PHONY: debug
debug:
	@echo OBJ = $(OBJ)

.PHONY: verify
verify: main.bin
	@bash verify.sh
