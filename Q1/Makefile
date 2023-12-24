CC = g++
CXXFLAGS = -std=c++17 -Wall -c
LDFLAGS = -std=c++17

OBJECTS = src/concatenate_string.o test/concatenate_string_test.o test/main.o

TARGET = test_q1

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgtest -o $(TARGET)

src/add_two_numbers.o: src/concatenate_string.c
	$(CC) $(CXXFLAGS) src/concatenate_string.c -o src/concatenate_string.o

test/add_two_numbers_test.o: test/concatenate_string_test.cpp
	$(CC) $(CXXFLAGS) test/concatenate_string_test.cpp -o test/concatenate_string_test.o

test/main.o: test/main.cpp
	$(CC) $(CXXFLAGS) test/main.cpp -o test/main.o

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./$(TARGET)