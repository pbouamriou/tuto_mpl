SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
EXE_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%,$(SRC_FILES))

all: $(OBJ_DIR) $(EXE_FILES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm $(EXE_FILES)

$(OBJ_DIR)/%: $(SRC_DIR)/%.cpp
	$(CXX) $< -o $@  