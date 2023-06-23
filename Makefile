# c++ compiler
CXX := g++
# compiler flags
CXX_VERSION_FLAG := -std=c++11

# paths
SRCDIR := src
HDRDIR := include
BUILDDIR := build
BINDIR := bin
TARGET := DirectionalPad

SRCEXT := cpp
HDREXT := hpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIBS := sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network
INC := -I include
CXXFLAGS := -L /usr/local/lib -l $(LIBS) -Wl,-rpath /Library/Frameworks

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@echo "\033[38;5;8m==> \033[0m\033[32;1mLinking\033[0m..."
	$(CXX) $(CXX_VERSION_FLAG) $^ -o $(BINDIR)/$(TARGET) $(INC) $(CXXFLAGS)
	@echo "\033[38;5;8m==> Created Unix Executable :\033[38;5;10m" $(TARGET) "\033[0m\033[38;5;8min" "\""$(BINDIR)"\"" "folder\033[0m"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HDRDIR)/%.$(HDREXT)
	@mkdir -p $(BUILDDIR)
	@echo "\033[38;5;8m==>\033[0m \033[34;1mCompiling\033[0m..."
	$(CXX) $(CXX_VERSION_FLAG) -Wall $(INC) -c -o $@ $<

clean:
	@echo "\033[38;5;8m==>\033[0m \033[33;1mCleaning\033[0m..."
	$(RM) -r $(BUILDDIR)
	$(RM) -r $(BINDIR)

run:
	@./$(BINDIR)/$(TARGET)
	
.PHONY: clean

