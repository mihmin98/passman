CC				:= gcc
CFLAGS			:= -Wall -Wextra
CXX				:= g++
CXXFLAGS		:= -std=c++11 -Wall -Wextra
LDFLAGS			:= -lstdc++fs
BUILD			:= ./build
OBJ_DIR			:= $(BUILD)/obj
APP_DIR			:= $(BUILD)/app
APPNAME			:= passman
INCLUDE_DIR		:= ./include
INCLUDE			:= -Iinclude
SRC_DIR			:= ./src
SRC 			:= $(wildcard $(SRC_DIR)/*.cpp) # All files that end in cpp
SRC_C			:= $(wildcard $(SRC_DIR)/*.c) # All files that end in c

OBJECTS			:= $(SRC:%.cpp=%.o) $(SRC_C:%.c=%.o) # Match all .cpp and .c files to .o files
OBJECTS			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJECTS)) # Replace the src dir path with the obj dir path


all: build $(APP_DIR)/$(APPNAME)

# Compile sources into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGFS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGFS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

# Link objects and create the executable
$(APP_DIR)/$(APPNAME): $(OBJECTS) 
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(APPNAME) $^ $(LDFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGFS += -DDEBUG -g
debug: all

release: CXXFLAGFS += -O2
release: all

clean:
	rm $(OBJ_DIR)/*.o $(APP_DIR)/$(APPNAME) $(APP_DIR)/*.passdat
