OBJDIR = bin
BIN_NAME = $(OBJDIR)/main
CODEDIRS = .

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(CFILES)))
DEPFILES = $(patsubst %.c,$(OBJDIR)/%.d,$(notdir $(CFILES)))

CC = gcc
CSTD = -std=c23
OPT = -O0
ANALYZER = -fanalyzer
WARNINGS = -Wall -Wextra -Werror \
           -Wpedantic -pedantic-errors \
           -Wformat=2 -Wconversion -Wsign-conversion \
           -Wshadow -Wstrict-prototypes \
           -Wmissing-prototypes -Wold-style-definition \
           -Wundef -Wwrite-strings \
           -Wcast-qual -Wswitch-enum \
           -Wnull-dereference \
           -Wdouble-promotion -Wvla
DEBUG = -g3
DEPFLAGS = -MMD -MP
CFLAGS = $(CSTD) $(OPT) $(DEBUG) $(WARNINGS) $(DEPFLAGS) $(ANALYZER)

all: $(BIN_NAME)
	./$(BIN_NAME)

valgrind: $(BIN_NAME)
	valgrind ./$(BIN_NAME)



$(BIN_NAME): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -MF $(OBJDIR)/$*.d -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

-include $(DEPFILES)

clean:
	rm -rf $(OBJDIR)

