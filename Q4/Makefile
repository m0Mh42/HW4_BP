CC = g++
CXXFLAGS = -std=c++17 -Wall -c
LDFLAGS = -std=c++17

OBJECTS = src/string_splitter.o test/string_splitter_test.o test/main.o

TARGET = test_q4

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgtest -o $(TARGET)

src/add_two_numbers.o: src/string_splitter.c
	$(CC) $(CXXFLAGS) src/string_splitter.c -o src/string_splitter.o

test/add_two_numbers_test.o: test/string_splitter_test.cpp
	$(CC) $(CXXFLAGS) test/string_splitter_test.cpp -o test/string_splitter_test.o

test/main.o: test/main.cpp
	$(CC) $(CXXFLAGS) test/main.cpp -o test/main.o

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./$(TARGET)
