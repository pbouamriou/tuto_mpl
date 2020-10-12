SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
EXE_FILES_11 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.11,$(SRC_FILES))
EXE_FILES_03 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.03,$(SRC_FILES))
TEST_FILES_11 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.11.test,$(SRC_FILES))
TEST_FILES_03 := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.03.test,$(SRC_FILES))
TEST_FILES := $(TEST_FILES_03) $(TEST_FILES_11)
EXE_FILES := $(EXE_FILES_03) $(EXE_FILES_11)
CPPFLAGS := -std=c++17 -ftemplate-depth=12000
CPPFLAGS_03 := -std=c++03 -ftemplate-depth=4000

all: $(OBJ_DIR) $(EXE_FILES)

c++11: $(EXE_FILES_11)

c++03: $(EXE_FILES_03)

test: $(TEST_FILES)

test11: $(TEST_FILES_11)

test03: $(TEST_FILES_03)

%.test: %
	@$< 1>&2 2> /dev/null; \
	if [ $$? -eq 0 ]; then \
		echo "PASSED: $$(basename $<)"; \
	else \
		echo "$$(tput setab 1)FAILED$$(tput sgr0): $$(basename $<)"; \
	fi

test2: $(EXE_FILES)
	@for exe in $(EXE_FILES) ; do \
		$$exe 1>&2 2> /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "PASSED: $$(basename $$exe)"; \
		else \
			echo "$$(tput setab 1)FAILED$$(tput sgr0): $$(basename $$exe)"; \
		fi \
	done

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm $(EXE_FILES)

$(OBJ_DIR)/%.11: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $< -o $@  

$(OBJ_DIR)/%.03: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS_03) $< -o $@  