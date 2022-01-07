OBJ_DIR = /Users/narasimha/personal/testApp/client/obj/
HDR_DIR = /Users/narasimha/personal/testApp/client/h/
UTILS_HDR_DIR = /Users/narasimha/personal/testApp/Utils/h/
UTILS_OBJ_DIR = /Users/narasimha/personal/testApp/Utils/obj/

all:
	g++ -c Client.cpp -o $(OBJ_DIR)/Client.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	g++ -c test/test1.cpp -o $(OBJ_DIR)/test1.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)
	g++ -c test/test2.cpp -o $(OBJ_DIR)/test2.o -I$(UTILS_HDR_DIR) -I$(HDR_DIR)

	g++ -o client1 $(OBJ_DIR)/Client.o $(OBJ_DIR)/test1.o $(UTILS_OBJ_DIR)/Utils.o
	g++ -o client2 $(OBJ_DIR)/Client.o $(OBJ_DIR)/test2.o $(UTILS_OBJ_DIR)/Utils.o

clean:
	rm $(OBJ_DIR)/*.o