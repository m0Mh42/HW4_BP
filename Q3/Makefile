CC = g++
CXXFLAGS = -std=c++17 -Wall -c
LDFLAGS = -std=c++17

OBJECTS = src/user_operations.o test/authorization_system_test.o test/main.o

TARGET = test_q3

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgtest -o $(TARGET)

src/user_operations.o: src/user_operations.c
	$(CC) $(CXXFLAGS) src/user_operations.c -o src/user_operations.o

test/authorization_system_test.o: test/authorization_system_test.cpp
	$(CC) $(CXXFLAGS) test/authorization_system_test.cpp -o test/authorization_system_test.o

test/main.o: test/main.cpp
	$(CC) $(CXXFLAGS) test/main.cpp -o test/main.o

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./$(TARGET)