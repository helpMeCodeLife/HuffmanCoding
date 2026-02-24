#include "./compressIntoBits.h"
#include "../files/readFile.h"
#include <string>
#include <vector>


void insertBit(char& target,char insertBit,int bitMask){
    target = target | (insertBit-'0')<<bitMask;
}

void compressIntoBits(std::string& huffmanCode){

  int size = huffmanCode.size();
  std::vector<std::string> vec;
  for(int i=0;i<size;i+=8){
    vec.push_back(huffmanCode.substr(i,8));
  }
  
  std::string compressedString = "";

  //first lets push the character count at the beginning, the character count will consume 4 bytes and the rest will be for 
  //the comrpressed data
  int characterCount = characterCountInFile("./files/inputFile.txt");
  compressedString.push_back((characterCount >> 24) & 0xFF);
  compressedString.push_back((characterCount >> 16) & 0xFF);
  compressedString.push_back((characterCount >> 8) & 0xFF);
  compressedString.push_back(characterCount & 0xFF);
 
  for(std::string eachString:vec){
    char target = 0;
    int size = eachString.size();
    for(int i=0;i<size;i++){
        insertBit(target,eachString[i],8-i-1);
    }
    compressedString.push_back(target);
  }
  huffmanCode = compressedString;
}
