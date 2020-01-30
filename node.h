//Kyle Werstlein
//1/29/20
//Node class for shutting yard algorithm.

class Node {
 public:
  Node();
  ~Node();
  char getData();
  void setData(char newdata);
  Node* getLeft();
  void setLeft(Node* newleft);
  Node* getRight();
  void setRight(Node* newright);
 private:
  char data;
  Node* leftP;
  Node* rightP;
};
