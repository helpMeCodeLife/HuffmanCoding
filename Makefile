CXX = g++
CXXFLAGS = -Wall -std=c++11 #or preferred c++ standard
TARGET = huffmanEncoder

SOURCES = main.cpp \
          huffmanTree/buildTree.cpp \
          priorityQueue/priorityQueue.cpp \
					huffmanTree/generateHuffmanCode.cpp \
					files/generateOutputFile.cpp \
					files/readFile.cpp \
					compression/compressIntoBits.cpp


HEADERS = huffmanTree/huffmanTree.h \
          priorityQueue/priorityQueue.h \
					huffmanTree/generateHuffmanCode.h \
					files/generateOutputFile.h \
					files/readFile.h \
					compression/compressIntoBits.h

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)
