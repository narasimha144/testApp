OBJ_DIR = /Users/narasimha/personal/testApp/obj/
HDR_DIR = /Users/narasimha/personal/testApp/server/h/
UTILS_HDR_DIR = /Users/narasimha/personal/testApp/Utils/h/
EXE_DIR = /Users/narasimha/personal/testApp/exe

all:
	g++ -c Server.cpp -o $(OBJ_DIR)/Server.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	g++ -c test/test.cpp -o $(OBJ_DIR)/test.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	
	g++ -o $(EXE_DIR)/server $(OBJ_DIR)/Server.o $(OBJ_DIR)/test.o $(OBJ_DIR)/Utils.o

clean:
	rm $(OBJ_DIR)/*.o