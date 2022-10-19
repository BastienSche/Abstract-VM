##
## EPITECH PROJECT, 2019
## AbstractVM
## File description:
## makefile
##

BIN 	=	abstractVM
SRC		=	src/*.cpp

all:	$(BIN)

$(BIN):
	g++ -g3 -Wall -Wextra $(SRC) -o $(BIN) -I./includes

clean:
	rm -rf *.o

fclean:
	rm -rf $(BIN)

re:
	make clean
	make fclean
	make all
