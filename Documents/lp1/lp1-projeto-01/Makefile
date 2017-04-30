##Created by Carlos Frederico Carvalheira Mello
##carvalheirafc@gmail.com
##since 24/04/17
##last 
##
##################################
BIN_DIR = ./bin
OBJ_DIR = ./build
INC_DIR = ./include
SRC_DIR = ./src
###################################

RM = rm -rf

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: dir clean
##################################

multimat:  $(OBJ_DIR)/main.o $(OBJ_DIR)/matrix.o $(OBJ_DIR)/filestream.o $(OBJ_DIR)/complementary.o
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^

$(OBJ_DIR)/complementary.o: $(SRC_DIR)/complementary.cpp $(INC_DIR)/complementary.hpp 
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/filestream.o: $(SRC_DIR)/filestream.cpp $(INC_DIR)/filestream.hpp 
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/matrix.o: $(SRC_DIR)/matrix.cpp $(INC_DIR)/matrix.hpp 
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	$(CC) -c $(CPPFLAGS) -o $@ $< 
	

 ###################################
dir: 
	mkdir $(BIN_DIR)
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(BIN_DIR)
	$(RM) $(OBJ_DIR)
