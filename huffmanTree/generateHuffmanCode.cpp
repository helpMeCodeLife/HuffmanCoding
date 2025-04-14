#include <vector>
#include "../priorityQueue/priorityQueue.h"

void treeTraversal(Node* root, std::string str,std::vector<EncodedCharacter>& vec){
  if(!root) return;
  if(root->left == nullptr && root->right == nullptr){
    EncodedCharacter newCh;
    newCh.character = root->data.character;
    newCh.code = str;
    vec.push_back(newCh);
    return;
  }
  treeTraversal(root->left,str+"0",vec);
  treeTraversal(root->right,str+"1",vec);
  return;
}

std::vector<EncodedCharacter> generateCode(Node* root){
  std::vector<EncodedCharacter> vec;
  treeTraversal(root,"",vec);

  return vec;

}

