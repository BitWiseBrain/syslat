CLANG ?= clang
ARCH := $(shell uname -m | sed 's/x86_64/x86/' | sed 's/aarch64/arm64/')

all: syslat.bpf.o loader

syslat.bpf.o: src/syslat.bpf.c
	$(CLANG) -g -O2 -target bpf -D__TARGET_ARCH_$(ARCH) -c $< -o $@

loader: src/loader.c
	gcc -o $@ $< -lbpf

clean:
	rm -f syslat.bpf.o loader

.PHONY: all clean
