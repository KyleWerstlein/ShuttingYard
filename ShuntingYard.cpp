//Kyle Werstlein
//1/28/20
//Shunting Yard Algorithm
#include<iostream>
#include<cstring>
#include"node.h"

using namespace std;

void stack_peek(Node* head, int count);
Node* stack_pop(Node* head, int count);
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
		  stackCurrentNode->setData(input[i]);
		  cout << "currentNode right start: " << stackCurrentNode->getRight() << endl;
		  if(stackHead == 0) {
			  stackHead = stackCurrentNode;
			  stackPreviousNode = stackHead;
			  nodeCount++;
		  }
		  else if(nodeCount == 1) {
		    stackHead->setRight(stackCurrentNode);
		    stackCurrentNode->setLeft(stackHead);
		    stackPreviousNode = stackCurrentNode;
		    nodeCount++;
		    stack_push(stackCurrentNode, stackHead);
		  }
		  else {
			stackPreviousNode->setRight(stackCurrentNode);
			stackCurrentNode->setLeft(stackPreviousNode);
			stack_push(stackCurrentNode, stackHead);
			stackPreviousNode = stackCurrentNode;
			nodeCount++;
			cout << "currentNode right end: " << stackCurrentNode->getRight() << endl;
		  }
      
      }
	  else if (input[i] > 47 && input[i] < 58) {
		  
	  }
    }
  }
  stack_peek(stackHead, nodeCount);
  return 0;
}

void stack_peek(Node* head, int count) {
  Node* peek;
  peek = stack_pop(head, count);
  //char printData = peek->getData();
  cout << peek->getData() << endl;
  stack_push(peek, head);
}

Node* stack_pop(Node* head, int count) {
  Node* leftP;
  Node* copy;
  for(int i = 0; i < count; i++){
    test(1);
    cout << "head data: " << head->getData() << endl;
    cout << "head adress: " << head << endl;
    if(head->getRight() != 0) {
      test(2);
      cout << "head right: " << head->getRight() << endl;
      head = head->getRight();
      cout << "head right2: " << head->getRight() << endl;
						     cout << "head right data: " << head->getRight()->getData() << endl;
														   cout << "i: " << i << endl;
    }
    else {
      test(3);
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
