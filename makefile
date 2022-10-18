#windows 10 
#COMPILER
CC = g++
#OUT
BIN = bin.exe
SRC = src\\
BUILD = build\\
#set config build and out objects
%.o : %.cpp
	$(CC) -c $< -o "$(BUILD)$@"
%.o : $(SRC)%.cpp
	$(CC) -c $< -o "$(BUILD)$@"
%.o : $(SRC)%.hpp
	$(CC) -c $< -o "$(BUILD)$@"
#build objects
complementos.o : $(SRC)\\complementos\\complementos.hpp
main.o : main.cpp
#object to boild in bin 
config: 
	mkdir $(BUILD)
#run tool
run: 
	.\\$(BUILD)$(BIN)
#build bin 
all: main.o complementos.o
	$(CC) -g "$(BUILD)*.o"  -o "$(BUILD)$(BIN)"
clean: 
	@cd $(BUILD)  && rm -f $(BIN) main.o complementos.o