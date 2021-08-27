CC=g++
STD=-std=c++11
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o



$(BUILD_DIR)/functions.o: cppFiles/functions.cpp
	$(CC) $(CF) -c cppFiles/functions.cpp -o $(BUILD_DIR)/functions.o

$(BUILD_DIR)/exceptions.o: cppFiles/exceptions.cpp
	$(CC) $(CF) -c cppFiles/exceptions.cpp -o $(BUILD_DIR)/exceptions.o

$(BUILD_DIR)/reply.o: cppFiles/reply.cpp
	$(CC) $(CF) -c cppFiles/reply.cpp -o $(BUILD_DIR)/reply.o

$(BUILD_DIR)/comment.o: cppFiles/comment.cpp
	$(CC) $(CF) -c cppFiles/comment.cpp -o $(BUILD_DIR)/comment.o

$(BUILD_DIR)/jeek.o: cppFiles/jeek.cpp
	$(CC) $(CF) -c cppFiles/jeek.cpp -o $(BUILD_DIR)/jeek.o

$(BUILD_DIR)/user.o: cppFiles/user.cpp
	$(CC) $(CF) -c cppFiles/user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/jeekjeek.o: cppFiles/jeekjeek.cpp
	$(CC) $(CF) -c cppFiles/jeekjeek.cpp -o $(BUILD_DIR)/jeekjeek.o


$(BUILD_DIR)/server_main.o: main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c main.cpp -o $(BUILD_DIR)/server_main.o


server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o  $(BUILD_DIR)/functions.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/reply.o $(BUILD_DIR)/comment.o $(BUILD_DIR)/jeek.o $(BUILD_DIR)/user.o $(BUILD_DIR)/jeekjeek.o $(BUILD_DIR)/server_main.o
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o  $(BUILD_DIR)/functions.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/reply.o $(BUILD_DIR)/comment.o $(BUILD_DIR)/jeek.o $(BUILD_DIR)/user.o $(BUILD_DIR)/jeekjeek.o $(BUILD_DIR)/server_main.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
