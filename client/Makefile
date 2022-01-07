OBJ_DIR = /Users/narasimha/personal/testApp/obj/
HDR_DIR = /Users/narasimha/personal/testApp/client/h/
UTILS_HDR_DIR = /Users/narasimha/personal/testApp/Utils/h/
EXE_DIR = /Users/narasimha/personal/testApp/exe

all:
	g++ -c Client.cpp -o $(OBJ_DIR)/Client.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	g++ -c test/test1.cpp -o $(OBJ_DIR)/test1.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	g++ -c test/test2.cpp -o $(OBJ_DIR)/test2.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)

	g++ -o $(EXE_DIR)/client1 $(OBJ_DIR)/Client.o $(OBJ_DIR)/test1.o $(OBJ_DIR)/Utils.o
	g++ -o $(EXE_DIR)/client2 $(OBJ_DIR)/Client.o $(OBJ_DIR)/test2.o $(OBJ_DIR)/Utils.o

clean:
	rm $(OBJ_DIR)/*.o