#makefile
MY_PATH = $(shell pwd)
BIN     = $(MY_PATH)/bin
HEAD    = $(MY_PATH)/head
SRC     = $(MY_PATH)/src
RES     = result
PRO     = words_analyse.c
MAIN    = main.c

all : install

install :
	gcc $(SRC)/$(PRO) $(SRC)/$(MAIN) -o $(BIN)/$(RES) -I $(HEAD)
run :
	@($(BIN)/$(RES))

.PHONY : clean
clean :
	rm $(BIN)/$(RES) -f

