BINARY=program
CODEDIRS=.        # top-level source dirs (you can add more: "CODEDIRS=. src")
BUILDDIR=bin

CC=gcc
OPT=-O0
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D,$(NCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

# find all subdirectories under CODEDIRS
ALLDIRS=$(shell find $(CODEDIRS) -type d)

# use those dirs for includes too
NCDIRS=$(ALLDIRS)
CFLAGS+= $(foreach D,$(NCDIRS),-I$(D))

# collect all .c files recursively
CFILES=$(foreach D,$(ALLDIRS),$(wildcard $(D)/*.c))

# map source files to build outputs (preserve directory structure under bin/)
OBJECTS=$(patsubst %,$(BUILDDIR)/%,$(CFILES:.c=.o))
DEPFILES=$(OBJECTS:.o=.d)

run: all
	valgrind --leak-check=full -s ./$(BUILDDIR)/$(BINARY)

all: $(BUILDDIR)/$(BINARY)

# link all objects into the final binary
$(BUILDDIR)/$(BINARY): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) -o $@ $^

# compile .c -> bin/<dir>/<file>.o
$(BUILDDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(BUILDDIR)

distribute: clean
	tar zcvf dist.tgz *

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

-include $(DEPFILES)

.PHONY: all clean distribute diff
