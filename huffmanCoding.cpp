#include <iostream>
#include "./pqHuffmanCoding.h"
Node* buildHuffmanTree(PriorityQueue& pq){
  while(pq.size()>1){
    Node* c1 = pq.dequeue();
    Node* c2 = pq.dequeue();
    
    Character temp;
    temp.character = 'N';
    temp.freq = c1->data.freq+c2->data.freq;

    Node* n1 = new Node(temp);
    n1->left = c1;
    n1->right = c2;
    pq.enqueue(n1);
  }

  return pq.dequeue();
}
int main(){
  Character c;
  c.character = 'c';
  c.freq = 5;
  Node* C = new Node(c);
  c.character = 'd';
  c.freq = 3;
  Node* D = new Node(c);
  
  PriorityQueue pq;
  pq.enqueue(C);
  pq.enqueue(D);

  buildHuffmanTree(pq);
  return 0;
}
