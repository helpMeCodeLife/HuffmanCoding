#include "./huffmanTree.h"
#include "../priorityQueue/priorityQueue.h"
Node* buildTree(PriorityQueue& pq){
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
