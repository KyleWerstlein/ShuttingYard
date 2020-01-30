//Kyle Werstlein
//1/30/20
//Shunting Yard Algorithm
#include "node.h"
Node::Node() {
  leftP = 0;
  rightP = 0;
  data = 0;
}

Node::~Node() {
  delete leftP;
  delete rightP;
}

char Node::getData() {
  return data;
}

Node* Node::getLeft() {
  return leftP;
}

Node* Node::getRight() {
  return rightP;
}

void Node::setData(char newdata) {
  data = newdata;
}

void Node::setLeft(Node* newleft) {
  leftP = newleft;
}

void Node::setRight(Node* newright) {
  rightP = newright;
}
