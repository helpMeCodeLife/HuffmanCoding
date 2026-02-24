#include <iostream>
#include "./generateOutputFile.h"
#include "../compression/compressIntoBits.h"
void generateOutputFile(std::string filePath,std::vector<EncodedCharacter> vec){
  std::ifstream inputFile(filePath);
  if(!inputFile){
    std::cout<<"error reading file"<<std::endl;
    return;
  }
  char ch;
  std::string huffmanCode;
  while(inputFile.get(ch)){
    for(EncodedCharacter ec:vec){
      if(ec.character == ch){
        huffmanCode+=ec.code;
        break;
      }
    } 
  }
  inputFile.close();

  compressIntoBits(huffmanCode);

  std::ofstream outputFile("files/outputFile.txt");

  outputFile<<huffmanCode;
  outputFile.close();
}
