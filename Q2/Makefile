CC = g++
CXXFLAGS = -std=c++17 -Wall -c
LDFLAGS = -std=c++17

OBJECTS = src/toeplitz_matrix.o test/toeplitz_matrix_test.o test/main.o

TARGET = test_q2

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgtest -o $(TARGET)

src/add_two_numbers.o: src/toeplitz_matrix.c
	$(CC) $(CXXFLAGS) src/toeplitz_matrix.c -o src/toeplitz_matrix.o

test/add_two_numbers_test.o: test/toeplitz_matrix_test.cpp
	$(CC) $(CXXFLAGS) test/toeplitz_matrix_test.cpp -o test/toeplitz_matrix_test.o

test/main.o: test/main.cpp
	$(CC) $(CXXFLAGS) test/main.cpp -o test/main.o

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./$(TARGET)