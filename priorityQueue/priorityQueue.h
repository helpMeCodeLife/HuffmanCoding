#pragma once

#include <vector>

class Character{
  public:
    char character;
    int freq;
};

class Node{
  public:
    Character data; 
    Node* left;
    Node* right;
    Node(Character);
};

class PriorityQueue{
  private:
    std::vector<Node*> vec;
    std::vector<Node*> dequeuedNodes;
    void heapify(std::vector<Node*>&,int,int);
    void swap(Node*,Node*);
  public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(Node*);
    Node* dequeue();
    int size();
};
