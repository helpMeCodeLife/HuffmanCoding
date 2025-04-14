#include <iostream>
#include "./priorityQueue/priorityQueue.h"
#include "./huffmanTree/huffmanTree.h"
#include "./files/readFile.h"
int main(){
  
  if(readFile("./files/inputFile.txt")){
    std::cout<<"file read";
  }
  return 0;
}
