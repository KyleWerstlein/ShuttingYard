#include<iostream>
#include<cstring>
#include "node.h"

using namespace std;

void enque(char token, int count, Node* head, Node* previousAdress);
void push(char token, int count, Node* head, Node* previousAdress);
char pop(Node* head);
char peek(Node* head, int count, Node* previousAdress);


int
main()
{
    char input[256];
    int qcount = 0;
    int scount = 0;
    Node* qPrevious = new Node();
    Node* qHead = new Node();
    Node* sPrevious = new Node();
    Node* sHead = new Node();
    Node* tmp;
    bool rightparcheck = false;
    cin.getline(input, 256); // take input
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
        { // skip spaces
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'
                || input[i] == '/' || input[i] == '^')
            { // if token is operator
                push(input[i], scount, sHead, sPrevious);
                scount++;
            }
            if (input[i] == '(')
            { // if token is opening parenthasis
                push(input[i], scount, sHead, sPrevious);
                scount++;
            }
            if (input[i] == ')')
            { // if token is closing parenthatsis
                while (peek(sHead, scount, sPrevious) != '(') {
                    rightparcheck = pop(sHead);
                    scount--;
                    if (rightparcheck != '(') {
                        enque(rightparcheck, qcount, qHead, qPrevious);
                    }
                }
                pop(sHead);
                scount--;
            }
            if (input[i] > 47 && input[i] < 58) // same as stack, popping and dequeing is when it's different.
            { // if token is a number
                enque(input[i], qcount, qHead, qPrevious);
                qcount++;
            }
        }
    }
    return 0;
}

/*bool
precedence(char token1, char token2) /////////////////UNUSED
{ //does token 1 have more precedence than token 2?
    int token1score = 0;
    int token2score = 0;
    if (token1 == '-' || token1 == '+')
    {
        token1score = 1;
    }
    else if (token1 == '*' || token2 == '/')
    {
        token1score = 2;
    }
    else if (token1 == '^')
    {
        token1score = 3;
    }
    if (token2 == '-' || token2 == '+')
    {
        token2score = 1;
    }
    else if (token2 == '*' || token2 == '/')
    {
        token2score = 2;
    }
    else if (token2 == '^')
    {
        token2score = 3;
    }
    if (token1score > token2score)
    {
        return true;
    }
    return false;
}
*/

char
pop(Node* head)
{
    Node* tmp2 = new Node();
    Node* tmp = head;
    while (tmp != 0) { // walk through link list
        tmp2 = tmp;
        tmp = tmp->getRight();
    }
    tmp2->getLeft()->setRight(NULL); // doesn't delete the node, just unlinks it from the list
    return tmp2->getData();
  /*  
    node->setData(tmp2->getData());
    node->setLeft(tmp2->getLeft());
    //node->setRight(tmp2->getRight());
    cout << tmp2 << endl;
    //cout << tmp->getLeft()->getRight() << endl;
    cout << node << endl;
    tmp2->getLeft()->setRight(0);
   // delete tmp2;
    return node;*/
}

void
push(char token, int count, Node* head, Node* previousAdress)
{
    Node* currentNode = new Node();
    if (count == 0) { // for the first node
        currentNode->setData(token);
        head = currentNode;
        previousAdress = head;
    }
    else if (count == 1) { // for second node
        currentNode->setData(token);
        currentNode->setLeft(head);
        head->setRight(currentNode);
        previousAdress = currentNode;
    }
    else { // everything after
        currentNode->setData(token);
        currentNode->setLeft(previousAdress);
        previousAdress->setRight(currentNode);
        previousAdress = currentNode;

    }
    Node* tmp = head;
   /* while (tmp != 0) {
        cout << tmp->getData() << endl;
        tmp = tmp->getRight();
    }*/
}

char peek(Node* head, int count, Node* previousAdress) {
    char tmp;
    tmp = pop(head);
    push(tmp, count, head, previousAdress);
    return tmp;
}

void
enque(char token, int count, Node* head, Node* previousAdress)
{
    Node* currentNode = new Node();
    if (count == 0) {
        currentNode->setData(token);
        head = currentNode;
        previousAdress = head;
    }
    else if (count == 1) {
        currentNode->setData(token);
        currentNode->setLeft(head);
        head->setRight(currentNode);
        previousAdress = currentNode;
    }
    else {
        currentNode->setData(token);
        currentNode->setLeft(previousAdress);
        previousAdress->setRight(currentNode);
        previousAdress = currentNode;
            
    }
    Node* tmp = head;
    /*while (tmp != 0) {
        cout << tmp->getData() << endl;
        tmp = tmp->getRight();
    }*/
}

void
deque()
{

}