# ===== Project name -> output filename =====
OUT ?= $(notdir $(CURDIR))

# ===== Platform-specific exe extension =====
ifeq ($(OS),Windows_NT)
  OUT_EXT ?= .exe
else
  OUT_EXT ?=
endif

# ===== Tools & flags =====
CXX      := g++
CXXFLAGS ?= -Wall -O3 -std=c++17

# Add include search paths (headers under include/, plus src/ if you keep local headers there)
INCLUDE_DIR := include
CXXFLAGS   += -I$(INCLUDE_DIR) -Isrc

# ===== Layout =====
OUT := myapp             # executable name
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# ===== Sources / Objects =====
SRCS_C    := $(wildcard $(SRC_DIR)/*.c)
SRCS_CPP  := $(wildcard $(SRC_DIR)/*.cpp)
SRCS      := $(SRCS_C) $(SRCS_CPP)

OBJS_C    := $(patsubst $(SRC_DIR)/%.c,   $(OBJ_DIR)/%.o, $(SRCS_C))
OBJS_CPP  := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS_CPP))
OBJS      := $(OBJS_C) $(OBJS_CPP)

# ===== Default target =====
default: all
all: $(BIN_DIR)/$(OUT)$(OUT_EXT)

# ===== Link =====
$(BIN_DIR)/$(OUT)$(OUT_EXT): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# ===== Compile (C / C++) =====
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===== Directories (order-only prerequisites) =====
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# ===== Housekeeping =====
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean default
.PRECIOUS: $(OBJ_DIR)/%.o

