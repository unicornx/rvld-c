
TESTS := $(wildcard tests/*.sh)

build:
	mkdir -p ./out/
	mkdir -p ./out/utils/
	mkdir -p ./out/linker/
	gcc -c utils/utils.c -o out/utils/utils.o -Wall
	gcc -c linker/file.c -o out/linker/file.o -Wall 
	gcc -c linker/inputfile.c -o out/linker/inputfile.o -Wall
	gcc -c linker/magic.c -o out/linker/magic.o -Wall
	gcc -c rvld.c -o out/rvld.o -Wall
	gcc out/utils/utils.o \
	    out/linker/file.o \
	    out/linker/inputfile.o \
	    out/linker/magic.o \
	    out/rvld.o \
	    -o out/rvld

test: build
	$(MAKE) $(TESTS)
	@printf '\e[32mPassed all tests\e[0m\n'

$(TESTS):
	@echo 'Testing' $@
	@./$@
	@printf '\e[32mOK\e[0m\n'

clean:
	rm -rf out/

.PHONY: build clean test $(TESTS)