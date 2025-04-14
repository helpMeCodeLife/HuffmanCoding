#pragma once

#include <vector>
#include <string>

class Character{
  public:
    char character;
    int freq;
};
class EncodedCharacter{
  public:
    char character;
    std::string code;
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
  public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(Node*);
    Node* dequeue();
    int size();
    void display();
};
