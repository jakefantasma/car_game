#windows 10 
#COMPILER
CC = g++
#OUT
BIN = bin.exe
SRC = src\\
BUILD = build\\
#set config build and out objects
%.o : %.cpp
	@echo "--------------"
	@echo $@
	@echo $<
	@echo "--------------"
	$(CC) -c $< -o "$(BUILD)$@"
%.o : %.hpp
	$(CC) -c $< -o "$(BUILD)$^"
#GAME CONFIG
GAME = src\\game\\
%.o : ${GAME}%.hpp
	@echo "--------------"
	@echo $@
	@echo $<
	@echo "--------------"
	$(CC) -c "$<" -o "$(BUILD)$@"
#COMPLEMENTOS CONFIG
COMPLE = src\\complementos\\
%.o : ${COMPLE}%.hpp
	@echo "--------------"
	@echo $@
	@echo $<
	@echo "--------------"
	$(CC) -c "$<" -o "$(BUILD)$@"
#create objects
main.o : main.cpp
game.o : ${GAME}game.hpp
complementos.o : ${COMPLE}complementos.hpp
#object to boild in bin 
config: 
	mkdir $(BUILD)
#run tool
run: 
	@cmd /c start cmd /k .\$(BUILD)\\$(BIN)
#build bin 
all : cl main.o 
	$(CC) -g "$(BUILD)*.o"  -o "$(BUILD)$(BIN)"
	@echo "build end"
cl: 
	rm -f build/*.o build/*.exe