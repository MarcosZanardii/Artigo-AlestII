EXEC = app

SRC = t1.cpp

OBJ = t1.o

all: $(EXEC) output

$(EXEC): $(OBJ)
	@g++ -o $(EXEC) $(OBJ)

$(OBJ): $(SRC)
	@g++ -c $(SRC)

output:
	@echo -n "casoa30.txt: "
	@./$(EXEC) < casoa30.txt
	@echo -n "casoa60.txt: "
	@./$(EXEC) < casoa60.txt
	@echo -n "casoa90.txt: "
	@./$(EXEC) < casoa90.txt
	@echo -n "casoa120.txt: "
	@./$(EXEC) < casoa120.txt
	@echo -n "casoa150.txt: "
	@./$(EXEC) < casoa150.txt
	@echo -n "casoa180.txt: "
	@./$(EXEC) < casoa180.txt
	@echo -n "casoa250.txt: "
	@./$(EXEC) < casoa250.txt
	@echo -n "casoa300.txt: "
	@./$(EXEC) < casoa300.txt 

clean:
	@rm -f $(OBJ) $(EXEC) resultado.txt
