# Generic Makefile for compiling an executable, with pkg-config dependencies.

CC := clang
PKGS := gtk+-3.0
SRCDIR := src
BUILDDIR := build
CFLAGS := -g -Wall `pkg-config --cflags $(PKGS)`
LIBS := `pkg-config --libs $(PKGS)`
TARGET := app

SRCEXT = c
SOURCES := `main.c`
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $^ -o $(TARGET) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<
clean:
	@echo " Cleaning..."; $(RM) -r $(BUILDDIR) $(TARGET)

-include $(DEPS)

.PHONY: clean
