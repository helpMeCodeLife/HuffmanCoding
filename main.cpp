#include <iostream>
#include "./priorityQueue/priorityQueue.h"
#include "./huffmanTree/huffmanTree.h"
#include "./files/readFile.h"
#include "./huffmanTree/generateHuffmanCode.h"
#include "./files/generateOutputFile.h"
void createNodes(PriorityQueue& pq,std::vector<Character>& characters){
  
  for(Character c:characters){
    Node* newNode = new Node(c);
    pq.enqueue(newNode);
  }
  return;
}

int main(){
  
  std::vector<Character> characters = readFile("./files/inputFile.txt");
  PriorityQueue pq;
  createNodes(pq,characters);
  
  Node* root = buildTree(pq);
  std::vector<EncodedCharacter> vec = generateCode(root);
  
  for(EncodedCharacter ec:vec){
    std::cout<<ec.character<<' '<<ec.code<<std::endl;
  }
  generateOutputFile("./files/inputFile.txt",vec);
  return 0;
}
