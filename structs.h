#ifndef STRUCTS_H
#define STRUCTS_H

#include <ctype.h>


typedef char* KeyType;
typedef char* InfoType;



typedef struct Node {
    KeyType key;
    InfoType info;
    struct Node* left;
    struct Node* right;
    struct Node* par;
} Node;


Node* addElement(Node* root, KeyType key, InfoType info);
KeyType readKey();
InfoType readInfo();
int printTree(Node* root, int step);
Node* findByKey(Node* root, KeyType key, int* k, int number);
Node* spetialSearch(Node* root, KeyType max, int number);
void printNode(Node* node);
int treeTraversal(Node* root, KeyType min, KeyType max);

int deleteNode(Node* root, KeyType key, int number);

Node* readFromFile(FILE* fb);

int freeTree(Node* root);



#endif