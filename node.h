//Kyle Werstlein
//1/29/20
//Node class for shutting yard algorithm.

class Node {
 public:
  Node();
  ~Node();
  char getData();
  Node* getLeft();
  Node* getRight();
 private:
  char data;
  Node* leftP;
  Node* rightP;
};
