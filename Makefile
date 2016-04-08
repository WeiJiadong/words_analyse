#makefile
MY_PATH = $(shell pwd)
BIN     = $(MY_PATH)/bin
HEAD    = $(MY_PATH)/head
SRC     = $(MY_PATH)/src
RES     = result
PRO1    = deal_note.c
PRO2    = externs_head_file.c
PRO3    = get_file.c
PRO4    = ident_init.c
PRO5    = is_ident.c
MAIN    = main.c
PRO     = $(SRC)/$(PRO1) $(SRC)/$(PRO2) $(SRC)/$(PRO3) $(SRC)/$(PRO4) $(SRC)/$(PRO5)
all : install

install :
	gcc $(PRO) $(SRC)/$(MAIN) -o $(BIN)/$(RES) -I $(HEAD)
run :
	@($(BIN)/$(RES))

.PHONY : clean
clean :
	rm $(BIN)/$(RES) -f

