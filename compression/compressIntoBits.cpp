#include "./compressIntoBits.h"
#include <iostream>
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
  for(std::string each:vec){
    std::cout<<each<<std::endl;
  }
  std::string compressedString = "";
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
