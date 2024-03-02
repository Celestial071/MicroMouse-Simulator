#will become useful when the project grows
CC = gcc
#source
SRC_DIR = ./src/
SRC = *.c
INC_DIR = -I./include
FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:
	$(CC) -g $(INC_DIR) $(SRC_DIR)$(SRC) -o main $(FLAGS)

