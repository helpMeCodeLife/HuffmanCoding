#include "./pqHuffmanCoding.h"

Node::Node(Character c){
      data.character = c.character;
      data.freq = c.freq;
      left = nullptr;
      right= nullptr;
}
void PriorityQueue::swap(Node* c1,Node* c2){
  Character temp;
  temp.character = c1->data.character;
  temp.freq = c1->data.freq;

  c1->data.character = c2->data.character;
  c1->data.freq = c2->data.freq;
  
  c2->data.character = temp.character;
  c2->data.freq = temp.freq;
  return;
}
PriorityQueue::PriorityQueue(){}
PriorityQueue::~PriorityQueue(){
  for(Node* node:vec){
    delete node;
  }
  for(Node* node:dequeuedNodes){
    delete node;
  }
}
void PriorityQueue::heapify(std::vector<Node*>& vec,int n,int i){
  int smallest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left<n && vec[smallest]->data.freq>vec[left]->data.freq){
    smallest = left;
  }
  if(right<n && vec[smallest]->data.freq>vec[right]->data.freq){
    smallest = right;
  }

  if(smallest != i){
    swap(vec[i],vec[smallest]);
    heapify(vec,n,smallest);
  }
  return;

}
void PriorityQueue::enqueue(Node* c){
  vec.push_back(c);
  if(vec.size() == 1) return; 
  int end = vec.size()-1;
  for(int i=(end-1)/2;i>0;i=(i-1)/2){
    heapify(vec,vec.size(),i);
  }
  heapify(vec,vec.size(),0);
  return;
}

Node* PriorityQueue::dequeue(){
  swap(vec[0],vec[vec.size()-1]);
  Node* c = vec[vec.size()-1];
  dequeuedNodes.push_back(c);
  vec.pop_back();
  heapify(vec,vec.size(),0);
  return c;
}
int PriorityQueue::size(){
  return vec.size();
}
