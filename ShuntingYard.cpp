//Kyle Werstlein
//1/28/20
//Shunting Yard Algorithm
#include<iostream>
#include<cstring>
#include"node.h"

using namespace std;

void stack_push(Node* node, Node* head);

int main() {
  char input[256];
  Node* head = new Node();
  Node* stackHead = new Node();
  Node* currentNode;
  Node* previousNode = head;
  cin.getline(input, 256);
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
      currentNode = new Node();
      previousNode->setRight(currentNode);
      currentNode->setLeft(previousNode);
      currentNode->setData(input[i]);
      if(currentNode->getData() == '*' || currentNode->getData() == '-' || currentNode->getData() == '+' || currentNode->getData() == '/') {
	stack_push(currentNode, stackHead);
      }
      previousNode = currentNode;
    }
  }
  return 0;
}

void stack_push(Node* node, Node* head) {
  bool loop = true;
  while(loop) {
    if(head->getRight() != 0) {
      head = head->getRight();
    }
    else {
      head->setRight(node);
      loop = false;
    }
  }
}
