CPP = g++
MYLIB = ../my-lib
FLAGS = -g
CPPFLAGS = -Wall -std=c++23 -I$(MYLIB)/include
LDFLAGS =
BIN_NAME = cache-sim
RM = rm

########################################################

SRC_DIR = src

BUILD_FOLDER = src/build

########################################################

SRC = $(wildcard ${SRC_DIR}/*.cpp)

headerfiles = $(wildcard ${SRC_FOLDER}/*.h)

OBJS = ${SRC:.cpp=.o}


########################################################

# implicit rules

%.o : %.cpp $(headerfiles)
	$(CPP) -c $(CPPFLAGS) $< -o $@

########################################################

all: $(BIN_NAME)
	@echo program compiled!
	@echo yes!

$(BIN_NAME): $(OBJS)
	$(CPP) -o $(BIN_NAME) $(OBJS) $(LDFLAGS)

clean:
	-$(RM) $(OBJS)
	-$(RM) $(BIN_NAME)

