//Kyle Werstlein
//1/28/20
//Shunting Yard Algorithm
#include<iostream>
#include<cstring>
#include"node.h"

using namespace std;

void stack_peek(Node* head);
Node* stack_pop(Node* head);
void stack_push(Node* node, Node* head);
void test(int testNum);

int main() {
  char input[256];
  Node* stackHead = new Node();
  stackHead = 0;
  Node* stackCurrentNode;
  int nodeCount = 0;
  Node* stackPreviousNode = stackHead;
  cin.getline(input, 256);
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
	  if(input[i] == '*' || input[i] == '-' || input[i] == '+' || input[i] == '/') {
		  stackCurrentNode = new Node();
		  stackCurrentNode->setData(input[1]);
		  if(stackHead == 0) {
			  stackHead = stackCurrentNode;
			  stackPreviousNode = stackHead;
			  nodeCount++;
		  }
		  else if(nodeCount == 1) {
		    stackHead->setRight(stackCurrentNode);
		  }
		  else {
			stackPreviousNode->setRight(stackCurrentNode);
			stackCurrentNode->setLeft(stackPreviousNode);
			stack_push(stackCurrentNode, stackHead);
			stackPreviousNode = stackCurrentNode;
		  }
      
      }
	  else if (input[i] > 47 && input[i] < 58) {
		  
	  }
    }
  }
  stack_peek(stackHead);
  return 0;
}

void stack_peek(Node* head) {
  Node* peek;
  peek = stack_pop(head);
  //char printData = peek->getData();
  cout << peek->getData() << endl;
  stack_push(peek, head);
}

Node* stack_pop(Node* head) {
  bool loop = true;
  Node* leftP;
  Node* copy;
  while(loop) {
    if(head->getRight() != 0) {
      head = head->getRight();
    }
    else {
      copy = head;
      leftP = head->getLeft();
      head = 0;
      leftP->setRight(0);
      return copy;
    }
  }
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

void test(int testNum) {
  cout << "test " << testNum << endl;
}
