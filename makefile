# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Archivos fuente y objetivo
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

# Regla principal
all: $(TARGET)

# Compilar y linkear
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpiar
clean:
	rm -f $(TARGET) src/*.o

.PHONY: all clean
