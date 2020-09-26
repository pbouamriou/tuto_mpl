SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
EXE_FILES_11 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.11,$(SRC_FILES))
EXE_FILES_03 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.03,$(SRC_FILES))
EXE_FILES := $(EXE_FILES_03) $(EXE_FILES_11)
CPPFLAGS := -std=c++11
CPPFLAGS_03 := -std=c++03

all: $(OBJ_DIR) $(EXE_FILES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm $(EXE_FILES)

$(OBJ_DIR)/%.11: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $< -o $@  

$(OBJ_DIR)/%.03: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS_03) $< -o $@  