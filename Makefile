-include $(DIR_OBJ)/*.d

DIR_BIN = bin
DIR_OBJ = $(DIR_BIN)/obj
DIR_INC = include
DIR_LIB = lib
DIR_SRC = src

TARGET 	= $(DIR_BIN)/sudoku
OBJS 	= $(DIR_OBJ)/main.o \
		$(DIR_OBJ)/control.o \
		$(DIR_OBJ)/functions.o \
		$(DIR_OBJ)/interface.o \

CFLAGS 	= -w -O3 -I$(DIR_INC)

$(TARGET) : $(OBJS)
	mkdir -p $(DIR_BIN)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(DIR_OBJ)/%.o : $(DIR_LIB)/%.c
	mkdir -p $(DIR_OBJ)
	gcc -c -MD $(CFLAGS) $< -o $@

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	mkdir -p $(DIR_OBJ)
	gcc -c -MD $(CFLAGS) $< -o $@

#cmd>> make clean
.PHONY : clean
clean:
	@rm -f -r $(DIR_BIN)