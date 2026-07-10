CXX ?= g++
CXXFLAGS ?= -std=c++11 -O2 -Wall -Wextra
INCLUDES = -Isrc/models -Isrc/services -Isrc/admin -Isrc/utils
BUILD_DIR = build
BIN = $(BUILD_DIR)/hospital

SOURCES = \
	src/main.cpp \
	src/models/Person.cpp \
	src/models/Patient.cpp \
	src/models/Docter.cpp \
	src/services/Reception.cpp \
	src/admin/Accountant.cpp \
	src/services/Hospital.cpp \
	src/admin/Admin.cpp \
	src/utils/Menu_Global.cpp

OBJECTS = \
	$(BUILD_DIR)/src/main.o \
	$(BUILD_DIR)/src/models/Person.o \
	$(BUILD_DIR)/src/models/Patient.o \
	$(BUILD_DIR)/src/models/Docter.o \
	$(BUILD_DIR)/src/services/Reception.o \
	$(BUILD_DIR)/src/admin/Accountant.o \
	$(BUILD_DIR)/src/services/Hospital.o \
	$(BUILD_DIR)/src/admin/Admin.o \
	$(BUILD_DIR)/src/utils/Menu_Global.o

all: $(BIN)

$(BIN): $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
