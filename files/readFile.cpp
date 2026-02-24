#include "./readFile.h"
#include <iostream>
#include "../priorityQueue/priorityQueue.h"
std::vector<Character> readFile(std::string filePath){
  std::ifstream inputFile(filePath);

  if(!inputFile){
    std::cout<<"error reading file"<<std::endl;
    return {};
  }
  char ch;
  std::vector<Character> characters;
  //map character -- frequency
  while(inputFile.get(ch)){
    bool charExists = false;
    if(ch=='\n') continue;
    for(Character& c:characters){
      if(c.character == ch){
        c.freq++;
        charExists = true;
        break;
      }
    }
    if(!charExists){
      Character c;
      c.freq =1;
      c.character = ch;
      characters.push_back(c);
    }
  }
  inputFile.close();
  return characters;
}

int characterCountInFile(std::string filePath){
  std::ifstream inputFile(filePath);
  if(!inputFile){
    std::cout<<"error reading file"<<std::endl;
    return -1;
  }
  std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
  inputFile.close();
  return content.size();
}
